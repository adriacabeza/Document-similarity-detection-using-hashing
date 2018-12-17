#include "kshingles.h"
#include "jaccard.h"
#include "jaccardaprox.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
ifstream inFile;

int main(){
    cout << setprecision(6) << fixed;

    cout << "> What do you want to do:" << endl;
    cout << "   1. Compare 2 documents" << endl;
    cout << "   2. Compare a batch of documents" << endl;
    int mode;
    cin >> mode;

    cout << "> Specify the size to use for the k-shingles [k]. e.g. 9" << endl;
    int k;
    cin >> k;

    vector<string> paths;

    switch(mode){
        case 1:{
            paths = vector<string>(2);
            cout << "> Enter the names of the 2 files. e.g. lorem_0.txt lorem_1.txt" << endl;
            string filename1, filename2;
            cin >> paths[0] >> paths[1];

            inFile.open("./input_texts/"+paths[0]);
            set<string> A = kshingles(&inFile,k,true,false,false);
            inFile.close();

            inFile.open("./input_texts/"+paths[1]);
            set<string> B = kshingles(&inFile,k,true,false,false);
            inFile.close();

            float sim_jacc =Jaccard(A,B);
            cout << "> Jaccard Similarity between " << paths[0] << " and " << paths[1] << " is " << sim_jacc << endl;
            break;
        }case 2:{
            cout << "> Enter batch name. e. g. lorem" << endl;
            string filename;
            cin >> filename;
            int i = 0;
            string input = "./input_texts/"+filename+"_";
            inFile.open(input+to_string(i)+".txt");
            while(inFile.good()){
                paths.push_back(input+to_string(i)+".txt");
                inFile.close();
                i++;
                inFile.open(input+to_string(i)+".txt");
            }
            inFile.close();

            cout << "> Specify the number of documents to work with (" << i << " files found). A large number here may result in very long processing times." << endl;
            int n;
            cin >> n;

            n = min(n, (int) paths.size());

            cout << "> What approach do you want:" << endl;
            cout << "   1. Calculating the Jaccard similarity for all the possible pair combinations in the document set" << endl;
            cout << "   2. Calculating a Jaccard similarity approximation via a computed signature matrix" << endl;
            cout << "   3. Calculating a Jaccard similarity approximation via a computed signature matrix with a locality-sensitive algorithm" << endl;

            int submode;
            cin >> submode;

            clock_t start;
            switch(submode){
                case 1:{
                    start = clock();
                    set<string> A, B;
                    for(int i = 0; i < n; ++i){
                        for(int j = i+1; j < n; ++j){
                            inFile.open(paths[i]);
                            A = kshingles(&inFile,k,true,false,false);
                            inFile.close();

                            inFile.open(paths[j]);
                            B = kshingles(&inFile,k,true,false,false);
                            inFile.close();

                            float sim_jacc =Jaccard(A,B);
                            cout << "> Jaccard Similarity between " << paths[i] << " and " << paths[j] << " is " << sim_jacc << endl;
                        }
                    }
                    cout << "> Finished in " << double(clock()-start)/CLOCKS_PER_SEC << " seconds" << endl;
                    break;
                }case 2:
                 case 3:{
                    cout << "> What hashing algorithm do you want:" << endl;
                    cout << "   1. Modular Hashing" << endl;
                    cout << "   2. Multiplicative Hashing" << endl;
                    cout << "   3. MurmurHash" << endl;
                    int hashmode;
                    cin >> hashmode;

                    int h;
                    int b;
                    int r;

                    if(submode == 2){
                        cout << "> Specify the number of hash functions to use [h]. e.g. 50" << endl;
                        cin >> h;
                    }else if(submode == 3){
                        cout << "> Specify the number of bands to use [b]. e.g. 10" << endl;
                        cin >> b;
                        cout << "> Specify the number of hash functions to use per band [r]. e.g. 5" << endl;
                        cin >> r;
                        h = b*r;
                    }

                    start = clock();
                    set<string> shingles_union;
                    vector<set<string>> shingles_doc(n);
                    for(int p = 0; p < n; ++p){
                        inFile.open(paths[p]);
                        shingles_doc[p] = kshingles(&inFile, k, false, true, true);
                        shingles_union.insert(shingles_doc[p].begin(), shingles_doc[p].end());
                        inFile.close();
                    }

                    vector<vector<unsigned int> > charactMatrix =  characteristicMatrix(shingles_doc, shingles_union);
                    vector<vector<unsigned int> > signatureMatrix;

                    switch (hashmode) {
                        case 1:
                            signatureMatrix =  modularHashing(charactMatrix, h);
                            break;
                        case 2:
                            signatureMatrix =  multiplicativeHashing(charactMatrix, h);
                            break;
                        case 3:
                            signatureMatrix =  murmurHashing(charactMatrix, h);
                            break;
                    }

                    if(submode == 2){
                        for(int i = 0; i < n; ++i){
                            for(int j = i+1; j < n; ++j){
                                float sim_jacc = sim(signatureMatrix, i, j);
                                cout << "> Jaccard Similarity (Approx.) between " << paths[i] << " and " << paths[j] << " is " << sim_jacc << endl;
                            }
                        }
                    }else if(submode == 3){
                        set<pair<unsigned int, unsigned int> > candidates = LSH(signatureMatrix, r, h);
                        cout << "> Found " << candidates.size() << " candidate pairs" << endl;
                        for(pair<unsigned int, unsigned int> p : candidates){
                            float sim_jacc = sim(signatureMatrix, p.first, p.second);
                            cout << "> Jaccard Similarity (Approx.) between " << paths[p.first] << " and " << paths[p.second] << " is " << sim_jacc << endl;
                        }
                    }
                    cout << "> Finished in " << double(clock()-start)/CLOCKS_PER_SEC << " seconds" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
