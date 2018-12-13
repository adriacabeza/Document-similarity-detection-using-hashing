#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include "kshingles.h"
#include "ModularHash.h"
using namespace std;

ifstream inFile;

unsigned int hash_vec(vector<unsigned int> const& vec) {
  unsigned int seed = vec.size();
  for(auto& i : vec) {
    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return seed;
}

pair<unsigned int,unsigned int> parella_inc(unsigned int a, unsigned int b){
    return (a < b) ? make_pair(a,b) : make_pair(b,a);
}

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

float sim(const vector<vector<unsigned int>> & signatureMatrix, int a, int b){
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

 vector<vector<unsigned int>> modularHashing(const vector<vector<unsigned int>> & repMatrix, int h){
    vector<vector<unsigned int>> signatureMatrix (h, vector<unsigned int> (repMatrix[0].size(), INFINITY));
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
    return signatureMatrix;
}

set<pair<unsigned int,unsigned int>> LSH(const vector<vector<unsigned int>> & signatureMatrix, int r, int h){
    set<pair<unsigned int,unsigned int>> candidats;                     //creem el LSH
    map<unsigned int,vector<unsigned int>> bucket;
    for(int i = 0; i < h; i+=r){
        bucket.clear();
        for(int j = 0; j < argc-1; ++j){
            vector<unsigned int> row;
            for(int k = 0; k < r; ++k){
                row.push_back(signatureMatrix[i+k][j]);
            }
            unsigned int doc1 = hash_vec(row);
            auto it = bucket.find(doc1);            
            if(it != bucket.end()){
                for(int l = 0; l < (it->second).size(); ++l ){  //al ser set, ordenem la parella de documents de forma creixent per a evitar repeticions
                    candidats.insert(parella_inc((it->second)[l], j));
                    
                }
                (it->second).push_back(j);
            }else{
                bucket.insert(it, pair<unsigned int, vector<unsigned int> >(doc1, vector<unsigned int>( 1 , j)));                
            }

        }
    }
    return candidats;
}

vector<vector<unsigned int>> characteristicMatrix(vector<set<string>> docShing, set<string> shingles){
    vector<vector<unsigned int>> repMatrix (shingles.size() , vector<unsigned int> (docShinng.size()));
    fill(repMatrix, shingles, docShing);
    return repMatrix;
}
