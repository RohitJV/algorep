/*
Use dynamic programming to calcute P[i][j] : (2^j)th parent of node 'i'
1) Compute L[] : Level of each node
           T[] : Parent of each node
2) Compute P[][] : if j==0, P[i][0]=T[i] (parent of 'i')
                   else, P[i][j] = P[P[i][j-1]][j-1]
3) Use meta-binary search to:
    a) Bring both the nodeto the same level
    b) Find LCA

https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/

Time Complexity:
Preprocessing time : O(NLogN)
Query Time : O(logN)
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

vector<int> v[MAX];
int n,m,q,s,l,r;
int T[MAX], L[MAX];
bool vis[MAX];
int P[MAX][20];

void dfs(int node, int parent, int level) {
    if(vis[node])
        return;
    vis[node]=true;

    T[node]=parent;
    L[node]=level;

    // Continue rescursively for all the children
    for(int i=0;i<v[node].size();i++) {
        dfs(v[node][i], node, level+1);
    }
}

int query(int x, int y) {
    if(L[x]<L[y])
        swap(x,y);

    // Use meta-binary search to bring both X and Y to the same level
    for(int i=s;i>=0;i--)
        if(L[x]-(1<<i) >= L[y])
            x=P[x][i];
    if(x==y)
        return x;

    // Again use meta-binary search to fint he LCA(x,y)
    for(int i=s;i>=0;i--) {
        if(P[x][i]!=-1 && P[x][i]!=P[y][i]) {
            x=P[x][i];
            y=P[y][i];
        }
    }
    return T[x];
}

int main() {
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    // s=log(n)
    for(s=1; (1<<s)<=n; s++);

    // compute p[][]
    memset(P, -1,sizeof(P));

    // Calculate Level and Parent
    dfs(0,-1,0);

    for(int i=0;i<n;i++) {
        P[i][0]=T[i];
    }
    for(int j=1;(1<<j)<n;j++)
        for(int i=0;i<n;i++)
            P[i][j]=P[P[i][j-1]][j-1];

    cin>>l>>r;
    cout<<"Result : "<<query(l,r);
}
