// Ref : TutorialPoints
// Ref : GeeksForGeeks
// Ref : Wikipedia

// You are Awesome

// Simple program to implement Jump search over a vector
// Vector must be sorted in ascending order
// O(log(n)), better perfomance than binary search,
// specially when elements lies uniformly over the range scale

// Basically we divide segement hi to lo, in uniformly
// and try to approximate the index at which the value 
// should lie.
// Using formula for mid = lo +      ((hi - lo) / (v[hi] - v[lo])  *   (value - v[lo]));
// (lo - hi) / (v[lo] - v[hi]) -> dividing (hi - lo) into (v[hi] - v[hi]) parts
// >> * (value - v[lo]) -> trying to approximate the position of the index for value

// Returns -1 if value not found
// else return first index of the value found

#include <bits/stdc++.h>
using namespace std;

int getMid(int lo, int hi, vector <int> &v, int value){
	int mid = lo + (1.0 * (hi - lo)/(v[hi] - v[lo]) * (value - v[lo]));
	return mid;
}

int InterpolationSearch(vector <int> &v, int value){
	int lo = 0;
	int hi = v.size()-1;
	int mid = getMid(lo, hi, v, value);

	do{
		if(lo == hi) return -1;

		if(v[mid] == value) return mid;

		if(value < v[mid])
			hi = mid - 1;
		else
			lo = mid + 1;

		mid = getMid(lo, hi, v, value);

	}while(true);

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

	int index = InterpolationSearch(v, value);
	if(index != -1){
		cout<<"Value found at index : "<<index<<endl;
	}
	else{
		cout<<"Value not found"<<endl;
	}

	return 0;
}
