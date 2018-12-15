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
    int k = 9;

    outFileTime.open("./output_data/lorem_jacc_vs_sim.txt");
    outFileTime << setprecision(6) << fixed;

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
    A = shingles_doc[1];
    inFile.close();

    float sim_jacc =Jaccard(A,B);

    for(int i = 1; i < 30; i++){
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
    outFileTime << endl;
    //cout << "Done: K = " << k << endl;


    outFileTime.close();
    return 0;
}
