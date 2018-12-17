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
    outFileTime.open("./output_data/"+filename+"_hashfuncts_time.txt");
    outFileTime << setprecision(6) << fixed;

    int b = 5;
    int r = 5;
    int h = b*r;

    for(int k : ks){

        outFileTime << k;
        set<string> shingles_union;
        vector<set<string>> shingles_doc(paths.size());
        for(int p = 0; p < paths.size(); ++p){
            inFile.open(paths[p]);
            shingles_doc[p] = kshingles(&inFile, k, false, true, true);
            shingles_union.insert(shingles_doc[p].begin(), shingles_doc[p].end());
            inFile.close();
        }

        vector<vector<unsigned int> > charactMatrix =  characteristicMatrix(shingles_doc, shingles_union);
        vector<vector<unsigned int> > signatureMatrix;

        clock_t start = clock();

        //Modular Hashing
        start = clock();
        signatureMatrix =  modularHashing(charactMatrix, h);
        outFileTime << "\t" << double(clock()-start)/CLOCKS_PER_SEC;

        //Multiplicative Hashing
        start = clock();
        signatureMatrix =  multiplicativeHashing(charactMatrix, h);
        outFileTime << "\t" << double(clock()-start)/CLOCKS_PER_SEC;

        //Murmur Hashing
        start = clock();
        signatureMatrix =  murmurHashing(charactMatrix, h);
        outFileTime << "\t" << double(clock()-start)/CLOCKS_PER_SEC;

        cout << "Done: K = " << k << endl;
        outFileTime << endl;
    }
    outFileTime.close();
    return 0;
}
