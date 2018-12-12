#include "kshingles.h"
#include "jaccard.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
ifstream inFile;
ofstream outFileSim, outFileTime;

int main(){
    set<string> A, B;
    //vector<string> paths {"./input_texts/Elretornodelrey.txt","./input_texts/harrypotter1.txt","./input_texts/Starwars.txt", "./input_texts/lorem.txt"};
    vector<string> paths {"./input_texts/Elretornodelrey.txt","./input_texts/harrypotter1.txt","./input_texts/Starwars.txt"};
    vector<int> ks {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    //vector<int> ks {15, 16};
    string filename = "out";
    outFileSim.open(filename+"_sim.txt");
    outFileSim << setprecision(10) << fixed;
    outFileTime.open(filename+"_time.txt");
    outFileTime << setprecision(6) << fixed;
    for(int k : ks){
        outFileSim << k;
        outFileTime << k;
        for(int i = 0; i < paths.size(); ++i){
            for(int j = i+1; j < paths.size(); ++j){
                clock_t start = clock();
                inFile.open(paths[i]);
                A = kshingles(&inFile,k,true,false,false);
                inFile.close();

                inFile.open(paths[j]);
                B = kshingles(&inFile,k,true,false,false);
                inFile.close();

                outFileSim << ",\t" << Jaccard(A,B);
                outFileTime << ",\t" << double(clock()-start)/CLOCKS_PER_SEC;
                cout << "Done: K = " << k << "\t" << paths[i] << "\t- " << paths[j] << endl;
            }
        }
        outFileSim << endl;
        outFileTime << endl;
    }
    outFileSim.close();
    outFileTime.close();
    return 0;
}
