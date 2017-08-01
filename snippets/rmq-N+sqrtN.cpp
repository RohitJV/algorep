/*
Divide the array into pices of sqrt(N) size and compute the minimum of each piece in O(N)
https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/

Time Complexity:
Preprocessing time : O(N)
Query Time : O(sqrt(N))
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
const   int            inf = 1000000;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

int n,x,q,l,r;
vector<int> v,m;

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        v.pb(x);
    }
    int s=sqrt(n);
    int cnt=0, val=v[0];
    for(int i=0;i<n;i++) {
        val=min(val,v[i]);
        cnt++;
        if(cnt==s) {
            m.pb(val);
            val=(i+1<n?v[i+1]:inf);
            cnt=0;
        }
    }
    if(val!=inf)
        m.pb(val);

    // print m[]
    // cout<<"\n";
    // for(int i=0;i<m.size();i++)
    //     cout<<m[i]<<" ";
    // cout<<"\n";

    //queries
    cin>>q;
    for(int i=0;i<q;i++) {
        // 'l' and 'r' are indexed from 1.
        cin>>l>>r;
        int L = (l+s-1)/s;
        int R = (r+s-1)/s;
        // Now, 'l', 'r', 'L', 'R' are all indexed from 0.
        L--; R--;
        l--; r--;
        int ans = inf;
        int l1=(l%s ? L+1 : L), r1=((r+1)%s ? R-1 : R);
        for(int j=l1;j<=r1;j++)
            ans=min(ans, m[j]);
        int j=l1*s-1;
        while(j>=0 && j>=l) {
            ans=min(ans,v[j]);
            j--;
        }
        j=(r1+1)*s;
        while(j<n && j<=r) {
            ans=min(ans,v[j]);
            j++;
        }
        cout<<"Result : "<<ans<<"\n";
    }
}
