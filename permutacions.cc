#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
ifstream inFile;
ofstream outFile;

set<string> paraules = {"a","an","the", "I", "you", "of", "he", "to", "she", "it", "we", "you", "they", "!", ",", ".", "-", "?"};
    

void writeVector(const vector<string>& A, int i,string nom){
    string s = "./input_texts/"+ nom + "_";
    ostringstream oss;
    oss << i<<".txt";
    s += oss.str();
    outFile.open(s);
    for(int j = 0; j < A.size(); ++j){
        outFile << A[j] <<" ";
    }
    outFile.close();
}

int main(){
    int n;
    cout << "How may permutations do you want?"<<endl;
    cin>>n; 
    string testline;
    string nom;
    cout << "Introduce the name of the file"<<endl;
    cin>> nom;
    inFile.open("./input_texts/"+nom);
    nom = nom.substr(0, nom.size() - 4);
    if(!inFile.is_open()){
        cout<<"The file does not exist"<<endl;
    }
    else{
        vector<string> words;
        while( inFile >> testline){
            words.push_back(testline); //insert each word in a vector of strings
        }
        inFile.close();
        for(int i = 0; i<n;++i){
            random_shuffle(words.begin(), words.end());
            writeVector(words,i,nom);
        }
    }
}
