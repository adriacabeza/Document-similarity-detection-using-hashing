#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include "kshingles.h"
using namespace std;

ifstream inFile;


void fill(vector<vector<unsigned int>> & repMatrix,const set<string> & shingles, const vector<set<string>> & docShing){
    
    for(int i = 0; i < repMatrix.size(); ++i ){
        repMatrix[i][0] = i;
        string shingle = *next(shingles.begin(), i);
        for(int j = 1; j < repMatrix[0].size(); ++j){
            if(docShing[j-1].find(shingle) != docShing[j-1].end()) repMatrix[i][j] = 1;
            else repMatrix[i][j] = 0;
        }
        
    }
    
}


int main(int argc, char** argv){
    
    set<string> shingles, aux;
    vector<set<string>> docShing (argc-1);
    for(int i = 1; i < argc; ++i ){
        inFile.open(argv[i]);
        aux = kshingles(&inFile, 9, false, true, true);
        shingles.insert(aux.begin(), aux.end());
        docShing[i-1] = aux;
        inFile.close();
    }
    vector<vector<unsigned int>> repMatrix (shingles.size() , vector<unsigned int> (argc));
    //cout << repMatrix.size() << " " << shingles.size() << " " << repMatrix[0].size() << endl;
    fill(repMatrix, shingles, docShing);
    
    
}
