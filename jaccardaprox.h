#ifndef JACCARDAPPROX_H
#define JACCARDAPPROX_H
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
#include "MultiplicativeHash.h"
#include "MurmurHash3.h"
using namespace std;

unsigned int hash_vec(vector<unsigned int> const& vec);

pair<unsigned int,unsigned int> parella_inc(unsigned int a, unsigned int b);

void fill(vector<vector<unsigned int>> & repMatrix,const set<string> & shingles, const vector<set<string>> & docShing);

float sim(const vector<vector<unsigned int>> & signatureMatrix, int a, int b);

void printmat(const vector<vector<unsigned int>> & mat);

vector<vector<unsigned int>> modularHashing(const vector<vector<unsigned int>> & repMatrix, int h);

vector<vector<unsigned int>> multiplicativeHashing(const vector<vector<unsigned int>> & repMatrix, int h);

vector<vector<unsigned int>> murmurHashing(const vector<vector<unsigned int>> & repMatrix, int h);

set<pair<unsigned int,unsigned int>> LSH(const vector<vector<unsigned int>> & signatureMatrix, int r, int h);

vector<vector<unsigned int>> characteristicMatrix(vector<set<string>> docShing, set<string> shingles);
#endif
