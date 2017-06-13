// ChandyShot...
// Pattern Count : https://www.hackerrank.com/contests/w33/challenges/pattern-count
// When Your Automata class comes in handy... 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 100010
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define tc int t; cin>>t; while(t--)
#define hello cout<<"hello"<<endl;
#define clr(x) memset(x, 0, sizeof (x))
#define fill(x) memset(x, -1, sizeof(x))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define f(i, j, k, l) for(int (i)=(j); (i)<(k); (i)+=(l))
#define ff(i, j, k, l) for(int (i)=(j); (i)<=(k); (i)+=(l))
#define fin f(i, 0, n, 1)
#define fjn f(j, 0, n, 1)
#define fiin ff(i, 1, n, 1)
#define fjjn f(j, 1, n, 1)
using namespace std;

istream& operator >> (istream &in, vector<int> &v){
    for(unsigned int i=0; i<v.size(); i++)
        cin>>v[i];
    return in;
}

int ans, idx;

void statef(string str);
void state1(string str);
void state2(string str);
void state3(string str);

void statef(string str){
    // cout<<"f";
    ans++;
    while(idx < str.length() and str[idx] == '1')
        idx++;
    if(idx == str.length())
        return;
    if(str[idx] == '0')
        state3(str);
    else
        state1(str);
}

void state3(string str){
    // cout<<"2";
    while(idx < str.length() and str[idx] == '0')
        idx++;
    if(idx == str.length())
        return;
    if(str[idx] == '1')
        statef(str);
    else
        state1(str);
}

void state2(string str){
    // cout<<"1";
    while(idx < str.length() and str[idx] == '1')
        idx++;
    if(idx == str.length())
        return;
    if(str[idx] == '0')
        state3(str);
    else
        state1(str);
}

void state1(string str){
    // cout<<"0";
    while(idx < str.length() and str[idx] != '1')
        idx++;
    if(idx == str.length())
        return;
    state2(str);
}

int solve(string str){
    state1(str);
    return ans;
}

int main(){
    // freopen("input.in", "r", stdin);
    tc{
        ans = 0, idx = 0;
        string str;
        cin>>str;
        cout<<solve(str)<<endl;
    }
}
