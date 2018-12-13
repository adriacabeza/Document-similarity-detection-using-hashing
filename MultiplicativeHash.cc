#include "MultiplicativeHash.h" 
#include <set> 


unsigned int computeValue(int k, int maxrow, float A){
    unsigned long w = 0x100000000;  //2 pow of 32 (32 is the word size)
   // float A = (sqrt(5) -1) /2.0 ; //proper Knuth value 
   
    unsigned int s = A*w;  
    long res = k * s; 
    res = res % w; //extracting the reminder of dividing by 2^(word size)
    unsigned int p = log2(maxrow); //number of bits desired for the hash  
    //p = rand() % (p+1); //PURA PATILLADA
    unsigned int resultat = res >> (32-p);
    return resultat; 
}

// int main(){
//     set<int> D; 
//     //int n;
//     //while(cin>>n){
//     int count = 0; 
//     for(int i = 0; i < 10000; ++i){
//         int b = computeValue(i,9050);
//         if(D.find(b) != D.end()){
//             cout<<"Repetio haha lol"<<endl;
//             ++count; 
//         }
//         else{
//             D.insert(b);
//         }      
//         cout <<"Value: "<<i<<" , hash value: " << b<<endl; 
//     }
//     cout << count<<endl; 
// }

