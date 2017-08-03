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

int n,a,b;
int x[1000],y[1000];
int res=0;

void check(int x1,int y1,int x2,int y2) {
    //cout<<x1<<","<<x2<<","<<y1<<","<<y2<<"\n";
    if(x1+x2<=a && max(y1,y2)<=b)
        res=max(res,x1*y1+x2*y2);
    if(x1+y2<=a && max(y1,x2)<=b)
        res=max(res,x1*y1+x2*y2);

    if(y1+x2<=a && max(x1,y2)<=b)
        res=max(res,x1*y1+x2*y2);
    if(y1+y2<=a && max(x1,x2)<=b)
        res=max(res,x1*y1+x2*y2);

        if(x1+x2<=b && max(y1,y2)<=a)
            res=max(res,x1*y1+x2*y2);
        if(x1+y2<=b && max(y1,x2)<=a)
            res=max(res,x1*y1+x2*y2);

        if(y1+x2<=b && max(x1,y2)<=a)
            res=max(res,x1*y1+x2*y2);
        if(y1+y2<=b && max(x1,x2)<=a)
            res=max(res,x1*y1+x2*y2);
}

int main() {
    cin>>n>>a>>b;
    for(int i=0;i<n;i++) {
        cin>>x[i]>>y[i];
    }

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            check(x[i],y[i],x[j],y[j]);
        }
    }
    cout<<res;
}
