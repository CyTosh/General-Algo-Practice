// Ref : GeeksForGeeks
// Ref : Wikipedia

// You are Awesome

// Simple program to implement Exponential search over a vector
// Vector must be sorted in ascending order
// O(log(n))

// It can be somewhat compared to jump search
// Rather than dividing the whole list into blocks each of size sqrt(v.size())
// We divide list into 1, 2, 4, 8,.. sized blocks;
// Then similar to jump search, we find block in which value may lie
// and make a binary search into that block

// Returns -1 if value not found
// else return first index of the value found

#include <bits/stdc++.h>
using namespace std;

inline int getLo(int lo, int blocksz, int n){
	return min(lo + blocksz, n);
}

inline int getHi(int lo, int blocksz, int n){
	return min(lo + 2*blocksz, n);
}

inline int getMid(int lo, int hi){
	return (lo + hi)/2;
}

int BinarySearch(std::vector<int> &v, int lo, int hi, int value){
	int mid = getMid(lo, hi);

	while(lo <= hi){
		if(v[mid] == value)		// if value found, return index;
			return mid;

		if(value < v[mid]){		// if value < v[mid], find in right half
			hi = mid - 1;
		}
		else if(v[mid] < value){	// if v[mid] < value, find in left half
			lo = mid + 1;
		}

		mid = getMid(lo, hi);		// set new mid, according as change in start or end
	}

	return -1;		// if value not found, return -1
}

int ExponentialSearch(vector <int> &v, int value){

	int n = v.size()-1;
	int lo = 0;
	int hi = 0;

	if(v[0] == value){
		return 0;
	}

	int blocksz = 1;	// represent current block size;
	while(true){
		lo = getLo(lo, blocksz, n);	// block starting index
		hi = getHi(lo, blocksz, n);	// block ending index

		//cout<<"lo = "<<lo<<", hi = "<<hi<<endl;

		if(v[hi] > value)
			break;

		if(lo == hi) 	// avoid infinite loop due to hi = n;
			return -1;

		blocksz = blocksz << 1;
	}

	// lo --> starting position of block that may contain value
	// hi --> ending position of block that may contain value

	int position = BinarySearch(v, lo, hi, value);	// we can use recursive version of InterpolationSearch

	return position;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];

	cout<<"Enter value to search : ";
	int value;
	cin>>value;

	int index = ExponentialSearch(v, value);
	if(index != -1){
		cout<<"Value found at index : "<<index<<endl;
	}
	else{
		cout<<"Value not found"<<endl;
	}

	return 0;
}
