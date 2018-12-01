#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;



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
	//J(A,B) = |A ∩ B|/|A U B|= |A ∩ B| / (|A|+|B| - |A ∩ B|)
	double size_intersection = intersection(A,B).size();
	cout<<"Size of A: "<<A.size()<<endl;
	cout<<"Size of B: "<<B.size()<<endl;
	cout<<"Size of the intersection: "<<size_intersection<<endl;
	double result = size_intersection / (A.size() + B.size() + size_intersection);
	cout<<"Jaccard coefficient: "<<result<<endl;
	return result;
}


int main(){
	vector<int> first {1,2,3,4,5,6};
	vector<int> second {6,5,7,8,9,10,12,14};

	vector<int> b = intersection(first, second);
	cout<<"Values that both sets have in common: ";
	for(int i = 0; i < b.size(); ++i){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	Jaccard(first,second); 
}
