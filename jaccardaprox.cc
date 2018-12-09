#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include "kshingles.h"
#include "ModularHash.h"
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

float sim(vector<vector<unsigned int>> & signatureMatrix, int a, int b){
    float simil = 0;
    for(int i = 0; i < signatureMatrix.size(); ++i){
        if(signatureMatrix[i][a] == signatureMatrix[i][b]) ++simil;
    }
    return (simil / signatureMatrix.size());
}

void printmat(const vector<vector<unsigned int>> & mat){
    for(int i = 0; i < mat.size(); ++i ){
        for(int j = 0; j < mat[i].size(); ++j){
            cout << mat[i][j] << " ";
        }
        cout << endl;
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
    fill(repMatrix, shingles, docShing);
    int b, r, h;
    cout << "Introdueix el numero de bandes i files que tindra el LSH" << endl;
    cin >> b >> r;
    h = r*b;
    vector<vector<unsigned int>> signatureMatrix (h, vector<unsigned int> (argc-1, INFINITY));
    vector<pair<int,int>> minHashMod(h);
    int value;
    srand (time(NULL));
    int prime =  NextPrime(repMatrix.size());                             //trobem el nombre primer mes proper al nombre de files
    for(int k = 0; k < h; ++k) minHashMod[k] = modHash(repMatrix.size()); //fem el vector de a y b de les funcions de hash modulars
    for(int i = 0; i < repMatrix.size(); ++i ){                           //comença el calcul de la signature matrix
        for(int j = 1; j < repMatrix[0].size(); ++j){
            if(repMatrix[i][j] == 1){
                for(int k = 0; k < h; ++k){
                    value = calcValue(minHashMod[k], prime, i);
                    if(value < signatureMatrix[k][j-1]) signatureMatrix[k][j-1] = value;
                }
            }
        }
    }
    printmat(repMatrix);
    for(int k = 0; k < h; ++k){
        cout << minHashMod[k].first << " , " << minHashMod[k].second << ": " << prime << endl;
    }
    printmat(signatureMatrix);
    cout << sim(signatureMatrix, 0, 1) << endl;
}
