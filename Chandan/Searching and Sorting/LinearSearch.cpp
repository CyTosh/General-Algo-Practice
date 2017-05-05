// Simple program to implement Linear search over a vector
// O(n)

// Returns -1 if value not found
// else return first index of the value found


#include <bits/stdc++.h>
using namespace std;

// int linearSearch(vector <int> &v, int value){
template <typename T> int linearSearch(vector <T> &v, T value){
	for(int i=0; i<v.size(); i++){
		if(value == v[i])
			return i;
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];

	cout<<"Enter value to search : ";
	int value;
	cin>>value;

	int index = linearSearch(v, value);
	if(index != -1){
		cout<<"Value found at index : "<<index<<endl;
	}
	else{
		cout<<"Value not found"<<endl;
	}

	return 0;
}
