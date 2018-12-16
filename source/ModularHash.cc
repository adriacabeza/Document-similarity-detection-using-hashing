#include "ModularHash.h"


pair<int,int> modHash(int maxrow){
    int a = rand() % maxrow;
    int b = rand() % maxrow;
    if (a == 0) a = 1;
    return make_pair(a, b);
}

int calcValue(pair<int, int> ab, int prime, int row){
    return (ab.first*row + ab.second)%prime;
}

bool IsPrime(int number){

    if (number == 2 || number == 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {

        if (number % (divisor - 1) == 0)
            return false;

        if (number % (divisor + 1) == 0)
            return false;

        divisor += 6;

    }

    return true;

}

int NextPrime(int a){

    while (!IsPrime(++a))
    { }
    return a;

}
