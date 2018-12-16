#ifndef MODHASH_H
#define MODHASH_H
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <utility>
using namespace std;
pair<int, int> modHash(int maxrow);
int calcValue(pair<int, int> ab, int prime, int row);
bool IsPrime(int number);
int NextPrime(int a);
#endif
