#include "kshingles.h"
#include "jaccard.h"
#include "jaccardaprox.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
ifstream inFile;
ofstream outFile;

int main(){
    cout << "Enter filename: (without .txt)" << endl;
    string filename;
    cin >> filename;
    vector<string> paths;
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

    outFile.open("./output_data/lorem_jacc_vs_sim_vs_lsh.txt");
    outFile << setprecision(6) << fixed;

    clock_t start;

    int k = 5;
    int b = 20;
    int r = 10;
    int h = b*r;

    //for(int n = 2; n < paths.size(); n++){
    for(int n = 2; n < 500; n++){
        outFile << n;

        //Normal Jaccard
        if(n<102){
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
                }
            }
            outFile << "\t" << double(clock()-start)/CLOCKS_PER_SEC;
        }else{
            outFile << "\t" << 0.0;
        }

        //Sim Approx
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

        signatureMatrix =  modularHashing(charactMatrix, h);
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                float sim_approx = sim(signatureMatrix, i, j);
            }
        }

        outFile << "\t" << double(clock()-start)/CLOCKS_PER_SEC;

        //LSH
        start = clock();
        set<string> shingles_unionL;
        vector<set<string>> shingles_docL(n);
        for(int p = 0; p < n; ++p){
            inFile.open(paths[p]);
            shingles_docL[p] = kshingles(&inFile, k, false, true, true);
            shingles_unionL.insert(shingles_docL[p].begin(), shingles_docL[p].end());
            inFile.close();
        }

        vector<vector<unsigned int> > charactMatrixL =  characteristicMatrix(shingles_docL, shingles_unionL);
        vector<vector<unsigned int> > signatureMatrixL;

        signatureMatrixL =  modularHashing(charactMatrixL, h);

        set<pair<unsigned int, unsigned int> > candidates = LSH(signatureMatrixL, r, h);
        for(pair<unsigned int, unsigned int> p : candidates){
            float sim_v = sim(signatureMatrixL, p.first, p.second);
        }
        outFile << "\t" << double(clock()-start)/CLOCKS_PER_SEC;
        outFile << "\t" << candidates.size();

        outFile << endl;
        cout << "n = " << n;
        cout << "\t" << candidates.size();
        cout << endl;
    }
    outFile.close();
    return 0;
}
