#include"ModularHash.h"

pair<int,int> modHash(int maxrow){
  srand (time(NULL));
  return make_pair(rand() % maxrow, rand() % maxrow);
}
