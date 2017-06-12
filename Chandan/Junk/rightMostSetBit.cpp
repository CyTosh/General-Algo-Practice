// Right most set bit
// ChandyShot... 

// REF      :   GEEKSFORGEEKS

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

ll pw(ll x, ll y){
    ll res = 1;
    if(y == 0)
        return 1;
    while(y){
        if(y&1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

istream& operator >> (istream &in, vector <int> &v){
    for(int i=0; i<v.size(); i++) in>>v[i];
    return in;
}

ll rightMostSetBit(ll n){
    return log2(n & (-n)) + 1;
    // -n = 2's complement of n,
    // n & -n, only rightmost bit will be set,
    // log2(n & (-n)), integral value of position, base 0;
}

ll rightMostSetBitt(ll n){
    if(n&1)
        return 1;

    int pos = 1;
    while(true){
        if(n&1){
            return pos;
        }
        n >>= 1;
        pos++;
    }
}

int main(){
    ll n;
    cin>>n;
    if(n!=0){
        cout<<rightMostSetBit(n)<<", ";
        cout<<rightMostSetBitt(n)<<endl;
    }
    else
        cout<<"none of the bit is set"<<endl;
    return 0;
}
