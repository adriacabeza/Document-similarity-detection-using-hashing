#include <iostream>
#include <string>
#include <set>
using namespace std;


/*VERSION USING VECTORS AND NOT SETS

template<typename T>
vector<T> intersection(vector<T> A, vector<T> B){
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	vector<int> result;
	set_intersection(A.begin(),A.end(),B.begin(),B.end(),back_inserter(result));
	return result;

}

template<typename T>
double Jaccard(vector<T> A, vector<T> B){

	double size_intersection = intersection(A,B).size();
	cout<<"Size of A: "<<A.size()<<endl;
	cout<<"Size of B: "<<B.size()<<endl;
	cout<<"Size of the intersection: "<<size_intersection<<endl;
	double result = size_intersection / (A.size() + B.size() - size_intersection);
	cout<<"Jaccard coefficient: "<<result<<endl;
	return result;
}*/

double intersection(const set<string>& A, const set<string>& B){
	int common = 0;
	auto it = A.begin(), it2 = B.begin();
	while(it!= A.end() and it2 != B.end()){
		if(*it < *it2){
			++it;
		}
		else if(*it > *it2){
			++it2;
		}
		else {
			++it;
			++it2;
			++common;
		}
	}
	return common;
}

double Jaccard(const set<string>& A, const set<string>& B){
//J(A,B) = |A ∩ B|/|A U B|= |A ∩ B| / (|A|+|B| - |A ∩ B|)
	double size_intersection = intersection(A,B);
	return size_intersection / (A.size() + B.size() - size_intersection);
}
