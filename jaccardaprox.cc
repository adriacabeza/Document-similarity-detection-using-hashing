#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <set>
using namespace std;

ifstream inFile;

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

void fill(vector<vector<unsigned char>> & repMatrix,const set<string> & shingles, const vector<set<string>> & docShing){
    
    for(int i = 0; i < repMatrix.size(); ++i ){
        repMatrix[i][0] = i;
        string shingle = *next(shingles.begin(), i);
        for(int j = 1; j < repMatrix[0].size(); ++j){
            if(docShing[j-1].find(shingle) != docShing[j-1].end()) repMatrix[i][j] = 1;
            else repMatrix[i][j] = 0;
        }
        
    }
    for(int x = 0; x < repMatrix.size(); ++x ){
        for(int k = 1; k < repMatrix[0].size(); ++k){
            cout << repMatrix[x][k] << " a ";
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
    vector<vector<unsigned char>> repMatrix (shingles.size() , vector<unsigned char> (argc-1));
    //cout << repMatrix.size() << " " << shingles.size() << " " << repMatrix[0].size() << endl;
    fill(repMatrix, shingles, docShing);
    
}
