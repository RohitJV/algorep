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
const   int            MAX  = 1000000;
const   int            MAXX  = 1000;

int tree[MAX+1], tree2d[MAXX+1][MAXX+1];
int n,m,q,x,y,z;

void update(int x, int val) {
    while(x<=MAX) {
        tree[x]+=val;
        // find the next index to be updated, which when read, should reflect the updated value of A[x]
        // This is done by adding the last set bit
        x = x + (x & -x);
    }
}

int read(int x) {
    int sum=0;
    while(x>0) {
        sum=sum+tree[x];
        // find the next index, by removing the last set bit
        x = x - (x & -x);
    }
    return sum;
}

void update2d(int x, int y, int val) {
    while(x<=MAXX) {
        int y1=y;
        while(y1<=MAXX) {
            tree2d[x][y1]+=val;
            y1 = y1 + (y1 & -y1);
        }
        x = x + (x & -x);
    }
}

int read2d(int x, int y) {
    int sum=0;
    while(x>0) {
        int y1=y;
        while(y1>0) {
            sum=sum+tree2d[x][y1];
            y1 = y1 - (y1 & -y1);
        }
        x = x - (x & -x);
    }
    return sum;
}

int main() {
    cin>>n;
    // cin>>n>>m;
    cin>>q;
    for(int i=0;i<q;i++) {
        //cin>>x>>y;
        cin>>x>>y>>z;
        //update(x,y);
        update2d(x,y,z);
    }

    cin>>q;
    for(int i=0;i<q;i++) {
        //cin>>x;
        cin>>x>>y;
        //cout<<read(x)<<"\n";
        cout<<read2d(x,y)<<"\n";
    }
}
