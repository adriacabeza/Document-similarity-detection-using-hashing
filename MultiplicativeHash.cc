#include "MultiplicativeHash.h" 
#include <set> 


unsigned int calcValue(int k){
    long res = k * s; 
    res = res % w; //extracting the reminder of dividing by 2^(word size)
    unsigned int resultat = res >> (32-p);
    return resultat; 
}
/*
int main(){
    set<int> A; 
    //int n;
    //while(cin>>n){
    int count = 0; 
    for(int i = 0; i < 10000; ++i){
        int b = calcValue(i);
        if(A.find(b) != A.end()){
            cout<<"Repetio haha lol"<<endl;
            ++count; 
        }
        else{
            A.insert(b);
        }      
        cout <<"Value: "<<i<<" , hash value: " << b<<endl; 
    }
    cout << count<<endl; 
}
*/
