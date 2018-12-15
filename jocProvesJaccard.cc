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

    vector<int> ks {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    outFileSim.open("./output_data/"+filename+"_out_sim.txt");
    outFileSim << setprecision(10) << fixed;
    outFileTime.open("./output_data/"+filename+"_out_time.txt");
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

                outFileSim << "\t" << Jaccard(A,B);
                outFileTime << "\t" << double(clock()-start)/CLOCKS_PER_SEC;
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
