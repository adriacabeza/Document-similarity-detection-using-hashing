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
    vector<string> paths {"./input_texts/lorem_0.txt","./input_texts/lorem_1.txt"};

    vector<int> ks {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    //vector<int> ks {15, 16};
    outFileTime.open("./output_data/lorem_jacc_vs_approx_time.txt");
    outFileTime << setprecision(6) << fixed;

    //int k = 9;


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

        //Normal Jaccard
        set<string> A, B;
        clock_t start = clock();
        inFile.open(paths[0]);
        A = shingles_doc[0];
        inFile.close();

        inFile.open(paths[1]);
        B = shingles_doc[1];
        inFile.close();

        float sim_jacc =Jaccard(A,B);

        outFileTime << "\t" << double(clock()-start)/CLOCKS_PER_SEC;

        //Approx
        int b = 5;
        int r = 5;
        int h = b*r;
        vector<vector<unsigned int> > charactMatrix =  characteristicMatrix(shingles_doc, shingles_union);
        vector<vector<unsigned int> > signatureMatrix;

        //Modular Hashing
        start = clock();
        signatureMatrix =  modularHashing(charactMatrix, h);

        float sim_approx = sim(signatureMatrix, 0, 1);

        outFileTime << "\t" << double(clock()-start)/CLOCKS_PER_SEC;

        cout << "Done: K = " << k << endl;
        outFileTime << endl;
    }
    outFileTime.close();
    return 0;
}
