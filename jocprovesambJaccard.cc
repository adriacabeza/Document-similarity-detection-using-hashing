#include "kshingles.h"
#include "jaccard.h"
#include <vector>
#include <string>

using namespace std;
ifstream inFile;
ofstream outFile;

int main(){

    vector<string> path {"Elretornodelrey.txt","harrypotter1.txt","Starwars.txt"};
    vector<int> k {3,9,18}; 
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            clock_t start = clock();
            inFile.open(path[j]);
            set<string> A = kshingles(&inFile ,k[i],true,false,false);
            inFile.close();

            inFile.open(path[(j+1)%3]); 
            set<string> B = kshingles(&inFile,k[i],true,false,false);
            inFile.close();

            outFile.open ("output.txt",std::ios_base::app);
            
            outFile<<"Jaccard Similarity between "<< path[j]<< " and "<< path[(j+1)%3]<< " using " << k[i] << "-shingles is "<< Jaccard(A,B)<<"."<<endl;
            
            outFile<<"Time "<<double(clock()-start)/CLOCKS_PER_SEC <<endl<<endl;
            outFile.close();
        }
    }
    return 0;
}
