#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

int main(){
    clock_t start = clock();
    int num;
    string path;
    int k;
    cout<<"Quants documents vols comparar?"<<endl;
    cin>>num;
    cout<<"Indica el path del primer document a comparar:"<<endl;
    cin>> path; 
    cout<<"De quin tamany vols els shingles?"<<endl;
    cin >> k; 
    //TODO: ficar una opció que sigui amb words o amb lletres
    //ARA JA HO TINC TOT INICIALITZAT
    //FICAR CODI PER A FER QUE UN DOCUMENT ES SEPARI EN KSHINGLES




    cout<<"Temps d'execució final:"<<double(clock()-start)/CLOCKS_PER_SEC <<endl;
}