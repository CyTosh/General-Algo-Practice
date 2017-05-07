// Ref : Wikipedia
// Ref : StackOverFlow
// Ref : GeeksForGeeks

// You are Awesome
// Learn alone to move fast
// Learn with society to move far

// Simple program to implement Jump search over a vector
// Vector must be sorted in ascending order
// O(sqrt(n)) for traversing of each block
// O(sqrt(n)) for linearSeaching in a block
// Therefore  O(sqrt(n)) + O(sqrt(n)) = O(sqrt(n))
// O(sqrt(n))

// Basically, we are dividing the whole vector into block size of sqrt(v.size());
// Then starting from index zero, increment steps by sqrt(v.size()) till we don't 
// reach the block in which value can lie, i.e. at maximum currentIndex for which
// v[currentIndex] < x, hold true;
// Then from make a linear search in this block, for v[currentIndex] == value;

// Somewhat Similar to square root decomposition technique


// Returns -1 if value not found
// else return first index of the value found

#include <bits/stdc++.h>
using namespace std;

template <typename T>
int JumpSearch(vector <T> &v, T value){
	int n = v.size()-1;
	int increment = (int)sqrt(n + 1);

	int prev = 0;
	int current = 0;

	if(value < v[0])		// if value is even lesser than first value
		return -1;		// we can't find that value

	// reaching to the block
	while(v[current] < value){

		current += increment;		// 	move to next block

		if(current > n)			//	avoid array out of bound
			current = n;

		if(prev == current)		// avoid infinite loop due to current = n;
			return -1;

		prev = current;
	}

	// now prev has the value of the index of block on which we have
	// to make linearSearch (we can make binary search also in this block)

	int start = prev;					// starting index of block
	int end = start + increment - 1;			// ending index of block
	if(end > n) end = n;					// avoid array out of bound

	for(int index = start; index <= end; index++){		// make linear search
		if(v[index] == value)
			return index;
	}

	return -1;		// value not found

}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];

	cout<<"Enter value to search : ";
	int value;
	cin>>value;

	int index = JumpSearch(v, value);
	if(index != -1){
		cout<<"Value found at index : "<<index<<endl;
	}
	else{
		cout<<"Value not found"<<endl;
	}

	return 0;
}
