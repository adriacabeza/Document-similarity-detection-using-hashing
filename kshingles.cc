#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <set>
using namespace std; 
set<string> kshingles(ifstream *in, int k, bool to_lowercase, bool keep_spaces, bool keep_punctuation){
	//TODO?: bool use_words?

	string n_text;
	set<string> s;
	
	char c;
	while (in->get(c)){
    	if((!ispunct(c) || keep_punctuation) && (!isspace(c) || keep_spaces)){
    		n_text.push_back(to_lowercase ? tolower(c) : c);
		}
	}

	for(int i = 0; i < n_text.length()-k+1; i++){
		string piece;
		for(int j = 0; j < k; j++){
			piece.push_back(n_text[i+j]);	
		}
		s.insert(piece);
	}

	return s;
}
