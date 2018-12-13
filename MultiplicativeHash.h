#ifndef MULTIHASH_H
#define MULTIHASH_H
#include <iostream>
#include <cmath> 
using namespace std;


unsigned int calcValue(int k);

unsigned long w = 0x100000000;  //2 pow of 32 (32 is the word size)
float A = (sqrt(5) -1) /2.0; //proper Knuth value 
int p = 14; //number of bits desired for the hash  
unsigned int s = A*w;  




#endif
