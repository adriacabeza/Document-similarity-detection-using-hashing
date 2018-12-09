#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>   
using namespace std;
ifstream inFile;
ofstream outFile;


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
    cout << "Fica el nombre de permutacions que vols"<<endl;
    cin>>n; 
    string testline; 
    string nom;
    cout << "Introdueix el nom de l'arxiu"<<endl; 
    cin>> nom; 
    inFile.open("./input_texts/"+nom);
    nom = nom.substr(0, nom.size() - 4);
    if(!inFile.is_open()){
        cout<<"The file does not exist"<<endl;
    }
    else{
        int i = 0; 
        vector<string> words; 
        while( inFile >> testline){
            words.push_back(testline);
        }
        inFile.close();
        for(i = 0; i<n;++i){
            random_shuffle(words.begin(), words.end());
            writeVector(words,i,nom);
        }
    }
}