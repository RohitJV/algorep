/*
Divide the tree into sections (level-wise) into sqrt(N) parts.
1) Compute L[] : Level of each node
           T[] : Parent of each node
2) Compute P[] : Ancestor in the last level of the upper net sections
3) Calculate LCA

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
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;
const   int            MAX = 1000;

vector<int> v[MAX];
int n,m,q,s,l,r;
int T[MAX], P[MAX], L[MAX];
bool vis[MAX];

void dfs(int node, int parent, int level) {
    if(vis[node])
        return;
    vis[node]=true;

    T[node]=parent;
    L[node]=level;

    // First section : Mark P[] as 1
    if(L[node]<s)
        P[node]=1;
    // For the first level in every section, P[i] = T[i]
    else {
        if (L[node]%s==0) {
            P[node]=T[node];
        }
        else {
            P[node] = P[T[node]];
        }
    }

    // Continue rescursively for all the children
    for(int i=0;i<v[node].size();i++) {
        dfs(v[node][i], node, level+1);
    }
}

int LCA(int x, int y) {
    //as long as the node in the next section of
    //x and y is not one common ancestor
    //we get the node situated on the smaller
    //lever closer
    while(P[x]!=P[y]) {
        if(L[x]>L[y])
            x=P[x];
        else
            y=P[y];
    }

    //now they are in the same section, so we trivially compute the LCA
    while(x!=y) {
        if(L[x]>L[y])
            x=T[x];
        else
            y=T[y];
    }
    return x;
}

int main() {
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    s=sqrt(n);
    // Populate L[], P[], T[]
    dfs(0,-1,0);
    // Compute LCA
    cin>>l>>r;
    cout<<"Result : "<<LCA(l,r)<<"\n";
}
