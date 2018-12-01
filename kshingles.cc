#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> kshingles(istream *in, int k, bool keep_repetitions, bool to_lowercase, bool keep_spaces, bool keep_punctuation){
	//TODO?: bool use_words?

	string n_text;
	set<string> s;
	vector<string> v;
	
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
		if(keep_repetitions) v.push_back(piece);
		else s.insert(piece);
	}

	if(!keep_repetitions) v.assign(s.begin(), s.end());

	return v;
}

int main(){
	
	vector<string> shingles = kshingles(&cin, 9, false, false, true, true);
	
	cout << "Computed " << shingles.size() << " k-shingles" << endl;
	
	/**for(string s : shingles){
		cout << s << endl;
	}**/
}
