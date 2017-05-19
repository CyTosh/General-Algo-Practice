// ChandyShot
// Selection sort

#include <bits/stdc++.h>
 
using namespace std;

istream & operator >> (istream &in, std::vector<int> &v){
	for (int i = 0; i < v.size(); ++i)
	{
		/* code */
		in>>v[i];
	}
}

ostream & operator << (ostream &out, std::vector<int> &v){
	for (int i = 0; i < v.size(); ++i)
	{
		/* code */
		out << v[i] << " ";
	}
	out<<endl;
}

void swap(int &a, int &b){
	if (&a != &b){
		a ^= b;
		b ^= a;
		a ^= b;
	} 
}

void selectionSort(std::vector<int> &v){

	for (int i = 0; i < v.size()-1; ++i)
	{
		/* code */
		int minm = v[i];
		int minm_idx = i;
		for (int j = i+1; j < v.size(); ++j)
		{
			/* code */
			if(minm > v[j]){
				minm = v[j];
				minm_idx = j;
			}

		}
		swap(v[minm_idx], v[i]);
	}
}

int main(){
	tc{
		int n;
		cin>>n;
		std::vector<int> v(n);
		cin>>v;
		selectionSort(v);
		cout<<v;
	}
	return 0;
}
