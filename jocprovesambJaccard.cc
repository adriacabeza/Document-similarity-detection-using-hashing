#include "kshingles.h"
#include "jaccard.h"
#include <vector>
#include <string>

using namespace std;
ifstream inFile;
ofstream outFile;

int main(){
    vector<string> path {"./input_texts/Elretornodelrey.txt","./input_texts/harrypotter1.txt","./input_texts/Starwars.txt"};
    vector<int> k {3,4,5,6,7,8, 9,10,18,22}; 
    outFile.open("output.txt");
    for(int i = 0; i < k.size(); ++i){
        for(int j = 0; j < 3; ++j){
            clock_t start = clock();
            inFile.open(path[j]);
            set<string> A = kshingles(&inFile ,k[i],true,false,false);
            inFile.close();

            inFile.open(path[(j+1)%3]); 
            set<string> B = kshingles(&inFile,k[i],true,false,false);
            inFile.close();
            // std::ios_base::app
            
            
            outFile<<"Jaccard Similarity between "<< path[j]<< " and "<< path[(j+1)%3]<< " using " << k[i] << "-shingles is "<< Jaccard(A,B)<<endl;
            cout << "Jaccard Similarity between "<< path[j]<< " and "<< path[(j+1)%3]<< " using " << k[i] << "-shingles is "<< Jaccard(A,B)<<endl;
            outFile<<"Time "<<double(clock()-start)/CLOCKS_PER_SEC <<endl<<endl;
         
        }
    }
    outFile.close();
    return 0;
}
