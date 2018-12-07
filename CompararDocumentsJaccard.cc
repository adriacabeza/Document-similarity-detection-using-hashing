#include "kshingles.h"
#include "jaccard.h"


using namespace std;

int main(){
    clock_t start = clock();
    int num;
    int k;
    string path;
    cout<<"Indica el path del primer document "<<num<< " a comparar:"<<endl;
    cin>> path; 
    string path2; 
    cout<<"Indica el path del segon document "<<num<< " a comparar:"<<endl;
    cin>> path2;
    cout<<"De quin tamany vols els shingles?"<<endl;
    cin >> k; 
    //TODO: ficar una opció que sigui amb words o amb lletres
    /*
    bool decom; 
    cout<<"Vols descompondre el document en paraules(0) o caràcters(1)?"
    cin>>descom;
    */
    //ARA JA HO TINC TOT INICIALITZAT

    ifstream ifs (path);
    ifstream ifs2 (path2);

    set<string> A = kshingles(ifs,k,true,false,false);
    set<string> B = kshingles(ifs2,k,true,false,false);
    cout<<"La diferència calculada per la Jaccard Similarity és de: "<< Jaccard(A,B);

    cout<<"Temps d'execució final:"<<double(clock()-start)/CLOCKS_PER_SEC <<endl;
}