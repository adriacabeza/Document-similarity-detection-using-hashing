#include "kshingles.h"
#include "jaccard.h"
#include "jaccardaprox.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
ifstream inFile;
ofstream outFileSim, outFileTime;

int main(){
    set<string> A, B;
    //vector<string> paths {"./input_texts/Elretornodelrey.txt","./input_texts/harrypotter1.txt","./input_texts/Starwars.txt", "./input_texts/lorem.txt"};
    //vector<string> paths {"./input_texts/Elretornodelrey.txt","./input_texts/harrypotter1.txt","./input_texts/Starwars.txt"};
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
    /**vector<int> ks {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    //vector<int> ks {15, 16};
    outFileSim.open("./output_data/"+filename+"_out_sim.txt");
    outFileSim << setprecision(10) << fixed;
    outFileTime.open("./output_data/"+filename+"_out_time.txt");
    outFileTime << setprecision(6) << fixed;**/

    //
    int k = 9;
    int b = 5;
    int r = 5;
    int h = b*r;
    //
    //for(int k : ks){
        //outFileSim << k;
        //outFileTime << k;
        set<string> shingles_union;
        vector<set<string>> shingles_doc(paths.size());
        for(int p = 0; p < paths.size(); ++p){
            inFile.open(paths[p]);
            shingles_doc[p] = kshingles(&inFile, k, false, true, true);
            shingles_union.insert(shingles_doc[p].begin(), shingles_doc[p].end());
            inFile.close();
        }

        vector<vector<unsigned int> > charactMatrix =  characteristicMatrix(shingles_doc, shingles_union);
        vector<vector<unsigned int> > signatureMatrix =  modularHashing(charactMatrix, h);
        set<pair<unsigned int, unsigned int> > candidates = LSH(signatureMatrix, r, h);
        for(pair<unsigned int, unsigned int> p : candidates){
            int a = p.first;
            int b = p.second;
            float sim_v = sim(signatureMatrix, a, b);
            cout << "Candidate " << paths[a] << " with " << paths[b] << " has similarity " << sim_v << endl;
        }
        ///////
                /**clock_t start = clock();
                inFile.open(paths[i]);
                A = kshingles(&inFile,k,true,false,false);
                inFile.close();

                inFile.open(paths[j]);
                B = kshingles(&inFile,k,true,false,false);
                inFile.close();

                outFileSim << "\t" << Jaccard(A,B);
                outFileTime << "\t" << double(clock()-start)/CLOCKS_PER_SEC;
                cout << "Done: K = " << k << "\t" << paths[i] << "\t- " << paths[j] << endl;**/
        //}
        //outFileSim << endl;
        //outFileTime << endl;
    //}
    //outFileSim.close();
    //outFileTime.close();
    return 0;
}
