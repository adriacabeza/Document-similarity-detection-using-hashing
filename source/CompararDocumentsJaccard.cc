#include "kshingles.h"
#include "jaccard.h"

ifstream inFile;

using namespace std;

int main(){
    clock_t start = clock();
    int k;
    string path;

    cout<<"De quin tamany vols els shingles?"<<endl;
    cin >> k;

    cout<<"Indica el path del primer document a comparar:"<<endl;
    cin>> path;

    inFile.open(path);
    set<string> A = kshingles(&inFile,k,true,false,false);
    inFile.close();

    cout<<"Indica el path del segon document a comparar:"<<endl;
    cin>> path;

    inFile.open(path);
    set<string> B = kshingles(&inFile,k,true,false,false);
    inFile.close();

    cout<<"La diferència calculada per la Jaccard Similarity és de: "<< Jaccard(A,B)<<endl;

    cout<<"Temps d'execució final:"<<double(clock()-start)/CLOCKS_PER_SEC <<endl;
}
