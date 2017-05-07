// Waking up to kiss you and nobody's there
// The smell of your perfume still stuck in the air
// It's hard
// Yesterday I thought I saw your shadow running round
// It's funny how things never change in this old town
// So far from the stars
// 								--This Town( Niall Horan )




// Simple program to implement Ternary search over a vector
// Vector must be sorted in ascending order

// log(n)

// Basic idea is to divide list into three parts
// and check each part for the occurence of value in it, and 
// choose our segment accordingly
// It's like binary search, where we divide list into 2 parts;
// Binary search have better perfomance than ternary search.

// Returns -1 if value not found
// else return index of the value found

#include <bits/stdc++.h>
using namespace std;

inline int getBlockSize(int start, int end){
	return (end - start)/3;
}

template <typename T>
int TernarySearch(vector <T> &v, T value){
	int start = 0;		// starting and ending of block chosen
	int end = v.size() - 1;
	int blocksz = getBlockSize(start, end);		// size of each block = (end - start)/3;

	int mid1 = start + blocksz;
	int mid2 = mid1 + blocksz;

	while(start <= end){
		if(v[mid1] == value) 
			return mid1;

		if(v[mid2] == value)
			return mid2;

		if(value < v[mid1])
			end = mid1 - 1;
		else if(value < v[mid2]){
			start = mid1 + 1;
			end = mid2 - 1;
		}
		else{
			start = mid2 + 1;
		}

		blocksz = getBlockSize(start, end);
		mid1 = start + blocksz;
		mid2 = mid1 + blocksz;
	}

	return -1;		// if value not found, return -1
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];

	cout<<"Enter value to search : ";
	int value;
	cin>>value;

	int index = TernarySearch(v, value);
	if(index != -1){
		cout<<"Value found at index : "<<index<<endl;
	}
	else{
		cout<<"Value not found"<<endl;
	}

	return 0;
}
