// You Are Awesome

// Simple program to implement Binary search over a vector
// Vector must be sorted in ascending order

// O(n) for bool isAlreadySorted(vector <T> &v);
// O(log(n)) for int BinarySearch(vector <T> &v, T value)
// Total = n + log(n) = n

// If we have already sorted Data, we can remove bool isAlreadySorted(vector <T> &v);  O(n)
// And make things work in log(n)

// Returns -1 if value not found
// else return index of the value found

#include <bits/stdc++.h>
using namespace std;

inline int getMid(int start, int end){
	return (start + end)/2;
}

template <typename T>
int BinarySearch(vector <T> &v, T value){
	int start = 0;
	int end = v.size() - 1;
	int mid = getMid(start, end);

	while(start <= end){
		if(value == v[mid]){	// if value found, return index;
			return mid;
		}

		else if(value < v[mid]){	// if value < v[mid], find in right half
			end = mid-1;
		}

		else if(v[mid] < value){	// if v[mid] < value, find in left half
			start = mid + 1;
		}

		mid = getMid(start, end);	// set new mid, according as change in start or end
	}

	return -1;		// if value not found, return -1
}

template <typename T>
bool isAlreadySorted(vector <T> &v){
	if(v.size() <= 1)
		return true;
	for(int i=1; i<v.size(); i++){
		if(v[i] >= v[i-1])
			// its in sorted order
			continue;
		else
			return false;
	}

	return true;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];

	if(!isAlreadySorted(v)){
		cout<<"Not sorted Elements !"<<endl;
		cout<<"Exiting...."<<endl;
		return 0;
	}

	cout<<"Enter value to search : ";
	int value;
	cin>>value;

	int index = BinarySearch(v, value);
	if(index != -1){
		cout<<"Value found at index : "<<index<<endl;
	}
	else{
		cout<<"Value not found"<<endl;
	}

	return 0;
}
