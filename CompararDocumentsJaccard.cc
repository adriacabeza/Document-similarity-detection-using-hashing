#include "kshingles.h"
#include "jaccard.h"

ifstream inFile;

using namespace std;

int main(){
    clock_t start = clock();
    int num;
    int k;
    string path;
    cout<<"Indica el path del primer document "<<num<< " a comparar:"<<endl;
    cin>> path;

    inFile.open(path);
    set<string> A = kshingles(inFile&,k,true,false,false);
    inFile.close();

    cout<<"Indica el path del segon document "<<num<< " a comparar:"<<endl;
    cin>> path;

    inFile.open(path);
    set<string> A = kshingles(inFile&,k,true,false,false);
    inFile.close();

    cout<<"De quin tamany vols els shingles?"<<endl;
    cin >> k;
    //TODO: ficar una opció que sigui amb words o amb lletres
    /*
    bool decom;
    cout<<"Vols descompondre el document en paraules(0) o caràcters(1)?"
    cin>>descom;
    */
    //ARA JA HO TINC TOT INICIALITZAT
    cout<<"La diferència calculada per la Jaccard Similarity és de: "<< Jaccard(A,B);

    cout<<"Temps d'execució final:"<<double(clock()-start)/CLOCKS_PER_SEC <<endl;
}
