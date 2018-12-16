#include "hash_stl.h" 
#include <set>

unsigned int calcValue(int n){
    hash<int> h;
    return h(n);
}


// int main(){
//     set<int> A; 
//     int count = 0; 
//     for(int i = 0; i < 10000; ++i){
//         int b = calcValue(i);
//         if(A.find(b) != A.end()){
//             cout<<"Repetio haha lol"<<endl;
//             ++count; 
//         }
//         else{
//             A.insert(b);
//         }      
//         cout <<"Value: "<<i<<" , hash value: " << b<<endl; 
//     }
//     cout << count<<endl; 
// }
