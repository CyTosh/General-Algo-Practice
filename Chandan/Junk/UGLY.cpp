// UGLY NUMBERS :   Ugly numbers are those whose only divisors are 2, 3 and 5;
//                  1 is ugly by convention, find nth ugly number
// REF : GEEKSFORGEEKS
// ChandyShot...

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

int n, curr;
int p2, p3, p5;
vector <int> ans;

istream& operator >> (istream &in, vector<int> &v){
    for(unsigned int i=0; i<v.size(); i++)
        cin>>v[i];
    return in;
}

int ugly(int n){
    if(n==1)
        return 1;
    
    ans[0] = 1;
    curr = p2 = p3 = p5 = 0;

    int next2 = ans[curr] * 2;
    int next3 = ans[curr] * 3;
    int next5 = ans[curr] * 5;

    for(int i=0; i<n; i++){

        int next = min(next2, min(next3, next5));
        ans[++curr] = next;

        // cout<<"next2 = "<<next2<<", ans[p2] = "<<ans[p2]<<endl;
        // cout<<"next3 = "<<next3<<", ans[p3] = "<<ans[p3]<<endl;
        // cout<<"next5 = "<<next5<<", ans[p5] = "<<ans[p5]<<endl;
        // cout<<"next  = "<<next<<endl;
        // cout<<endl;


        if(next == next2){
            p2++;
            next2 =  ans[p2] * 2;
        }

        if(next == next3){
            p3++;
            next3 =  ans[p3] * 3;
        }

        if(next == next5){
            p5++;
            next5 =  ans[p5] * 5;
        }
    }
    return ans[n-1];
}

int main(){
    int n;
    cin>>n;
    ans.resize(n+1);
    cout<<ugly(n)<<endl;
    for(int i=0; i<10; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
