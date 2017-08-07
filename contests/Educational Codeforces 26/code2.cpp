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

vector<string> s;
int n,m;
string x;
bool res=false;

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>x;
        s.pb(x);
    }

    int check=0;
    if(n%3==0) {
        for(int i=0;i<3;i++) {
            bool flag=true;
            char ch = s[n/3*i][0];
            for(int j=n/3*i;j<n/3*(i+1);j++) {
                for(int k=0;k<m;k++) {
                    if(s[j][k]!=ch) {
                        flag=false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(flag) {
                if(ch=='R')
                    check=check|1;
                else if(ch=='G')
                    check=check|2;
                else if(ch=='B')
                    check=check|4;
            }
        }
        if(check==7)
            res=res|true;
        else
            res=res|false;
    }
    if(m%3==0) {
        for(int i=0;i<3;i++) {
            bool flag=true;
            char ch = s[0][m/3*i];
            for(int j=m/3*i;j<m/3*(i+1);j++) {
                for(int k=0;k<n;k++) {
                    if(s[k][j]!=ch) {
                        flag=false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(flag) {
                if(ch=='R')
                    check=check|1;
                else if(ch=='G')
                    check=check|2;
                else if(ch=='B')
                    check=check|4;
            }
        }
        if(check==7)
            res=res|true;
        else
            res=res|false;
    }
    if(res)
        cout<<"YES";
    else
        cout<<"NO";
}
