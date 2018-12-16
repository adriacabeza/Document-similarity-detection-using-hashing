#include "MultiplicativeHash.h" 
#include <set> 


unsigned int computeValue(int k, int maxrow, float A){
    unsigned long w = 0x100000000;  //2 pow of 32 (32 is the word size)
   // float A = (sqrt(5) -1) /2.0 ; //proper Knuth value 
    unsigned int s = A*w;  
    long res = k * s; 
    res = res % w; //extracting the reminder of dividing by 2^(word size)
    unsigned int p = log2(maxrow); //number of bits desired for the hash  
    unsigned int resultat = res >> (32-p);
    return resultat; 
}

