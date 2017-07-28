/*
Using Sparse Table to store the index of the minimum element in the subarray
https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/

Time Complexity:
Preprocessing time : O(N LogN)
Query Time : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)

typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;
const   int            MAX = 1000000;

int n,q,x,l,r;
int m[MAX][20];
vector<int> v;

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    // m[][] contains the index of the minimum value in the subarray [i,i+2^j]
    for(int i=0;i<n;i++)
        m[i][0]=i;
    for(int j=1; (1<<j)<=n;j++) {
        for(int i=0;(i+(1<<j)-1)<n;i++) {
            if(v[m[i][j-1]] <= v[m[i+(1<<(j-1))][j-1]])
                m[i][j]=m[i][j-1];
            else
                m[i][j]=m[i+(1<<(j-1))][j-1];
        }
    }

    // queries
    cin>>q;
    for(int i=0;i<q;i++) {
        cin>>l>>r;
        l--; r--;
        int res=0;
        int k=0;
        while(pow(2,k)<=r-l+1)
            k++;
        k--;
        cout<<"Result : "<<min(v[m[l][k]], v[ m[r-(int)pow(2,k)+1][k] ]);
    }
}
