```cpp
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<sstream>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define per(i,n,x) for(int i=n;i>=x;i--)
#define sz(a) int(a.size())
#define rson mid+1,r,p<<1|1
#define pii pair<int,int>
#define lson l,mid,p<<1
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
using namespace std;
const double eps=1e-8;
const int mod=1e9+7;
const int N=1e6+10;
const int inf=1e9;
int T,n,m;
int q[N],L[N],R[N];
int main(){
    ios::sync_with_stdio(false);
    //freopen("in","r",stdin);
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<vector<int> >a(n+10,vector<int>(m+10,0));
        vector<vector<int> >s(n+10,vector<int>(m+10,0));
        vector<vector<int> >t(n+10,vector<int>(m+10,0));
        rep(i,1,n) rep(j,1,m) cin>>a[i][j];
        rep(i,1,n) rep(j,1,m){
            if(a[i][j]) s[i][j]=s[i-1][j]+1;
            else t[i][j]=t[i-1][j]+1;
        }
        int ans=0;
        rep(i,1,n){
            int l=0,r=-1;
            rep(j,1,m) R[j]=m+1;
            rep(j,1,m){
                while(l<=r&&s[i][q[r]]>s[i][j]){ // 找右边界
                    R[q[r]]=j;
                    --r;
                }
                // 找左边界 1 和或者比 s[i][j] 更小的下标 + 1
                if(l<=r) L[j]=q[r]+1
                else L[j]=1;
                q[++r]=j;
            }
            rep(j,1,m) ans=max(ans,(R[j]-L[j])*s[i][j]);
            l=0,r=-1;
            rep(j,1,m) R[j]=m+1;
            rep(j,1,m){
                while(l<=r&&t[i][q[r]]>t[i][j]){
                    R[q[r]]=j;
                    --r;
                }
                if(l<=r) L[j]=q[r]+1;
                else L[j]=1;
                q[++r]=j;
            }
            rep(j,1,m) ans=max(ans,(R[j]-L[j])*t[i][j]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
```
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
int q[N], a[N], R[N], L[N];

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i); 

    int l = 0, r  = -1; 
    for (int i = 1; i <= n; ++i) R[i] = n + 1;
    for (int i = 1; i <= n; ++i) {
        while (l <= r && a[q[r]] > a[i]) {
            R[q[r]] = i;
            --r;
        }
        if (l <= r) L[i] = q[r] + 1;
        else L[i] = 1;
        q[++r] = i;
    }   

    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    puts("");
    for (int i = 1; i <= n; ++i) printf("%d ", L[i]);
    puts("");
    for (int i = 1; i <= n; ++i) printf("%d ", R[i]);
    puts("");
}
```
