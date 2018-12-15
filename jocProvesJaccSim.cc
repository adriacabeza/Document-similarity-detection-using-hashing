#include "kshingles.h"
#include "jaccard.h"
#include "jaccardaprox.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
ifstream inFile;
ofstream outFileSim;

int main(){
    vector<string> paths {"./input_texts/lorem_99.txt","./input_texts/lorem_100.txt"};
    int k = 9;

    outFileSim.open("./output_data/lorem_jacc_vs_sim.txt");
    outFileSim << setprecision(6) << fixed;

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
    inFile.open(paths[0]);
    A = shingles_doc[0];
    inFile.close();

    inFile.open(paths[1]);
    B = shingles_doc[1];
    inFile.close();

    float sim_jacc = Jaccard(A,B);

    //for(int t = 1; t < 300; t++){
    for(int t = 1; t < 300; t++){
        //Approx
        vector<vector<unsigned int> > charactMatrix =  characteristicMatrix(shingles_doc, shingles_union);
        vector<vector<unsigned int> > signatureMatrix;

        //Modular Hashing
        signatureMatrix =  modularHashing(charactMatrix, t);

        float sim_approx = sim(signatureMatrix, 0, 1);

        outFileSim << t << "\t" << sim_jacc << "\t" << sim_approx << endl;

        cout << "Done: t = " << t << endl;
    }

    outFileSim.close();
    return 0;
}
