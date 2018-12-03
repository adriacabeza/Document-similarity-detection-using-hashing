#ifndef FOOP_H
#define FOOP_H
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <set>
using namespace std;
set<string> kshingles(ifstream *in, int k, bool to_lowercase, bool keep_spaces, bool keep_punctuation);
#endif
