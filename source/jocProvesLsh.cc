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

    outFile.open("./output_data/lorem_lsh.txt");
    outFile << setprecision(6) << fixed;

    int k = 9;
    vector<int> bs {1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 16, 20, 24, 30, 40, 48, 60, 80, 120, 240};
    int h = 240;

    for(int b : bs){
        int r = h/b;

        outFile << b << "\t" << r;

        //LSH
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

        signatureMatrix =  modularHashing(charactMatrix, h);

        set<pair<unsigned int, unsigned int> > candidates = LSH(signatureMatrix, r, h);
        outFile << "\t" << candidates.size();

        outFile << endl;
        cout << "b = " << b;
        cout << endl;
    }
    outFile.close();
    return 0;
}
