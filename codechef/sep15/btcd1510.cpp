#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LL long long
#define sd(x) scanf("%d", &x)
#define sld(x) scanf("%lld", &x)
#define MOD 1000000007
#define SQ 2000
#define N 112345
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = A; I <= B; ++I)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>
 
int vis[N], par[N], arr[N], dp[N][30], hi[N];
vector<pair<int, int> > adj[N];
 
inline int dfs(int x){
    vis[x] = 1;
    int i, ch;
    for(i = 0; i < adj[x].size(); i++){
        ch = adj[x][i].F;
        if(vis[ch] == 0){
            hi[ch] = hi[x] + 1;
            arr[ch] = adj[x][i].S;
            par[ch] = x;
            dfs(ch);
        }
    }
}
 
int get_anc(int x, int y){
    if(x == y){
        return x;
    }
    int i;
    if(hi[x] < hi[y]){
        swap(x, y);
    }
    for(i = 20; i >= 0; i--){
        if( (hi[x] - (1 << i)) >= hi[y]){
            x = dp[x][i];
        }
    }
    if(hi[x] != hi[y]){
        while(1);
    }
    for(i = 20; i >= 0; i--){
        if(dp[x][i] != dp[y][i]){
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    if(x == y){
        return x;
    }
    else if(par[x] == par[y]){
        return par[x];
    }
    else{
        while(1);
    }
}
 
int solve(){
 
    int n, i, x, y, c, xo, val, j, anc;
    cin>>n;
    MS0(vis);
    for(i = 1; i <= n; i++){
        adj[i].clear();
    }
    for(i = 1; i < n; i++){
        sd(x);
        sd(y); sd(c);
        adj[x].PB(MP(y, c));
        adj[y].PB(MP(x, c));
    }
    hi[1] = 1;
    par[1] = 0;
    dfs(1);
    for(i = 1; i <= n; i++) dp[i][0] = par[i];
    for(i = 1; i <= 20; i++){
        for(j = 1; j <= n; j++){
            dp[j][i] = dp[ dp[j][i - 1] ][i - 1];
        }
    }
    int q;
    sd(q);
    while(q--){
        sd(x);
        sd(y);
        sd(xo);
        if(x == y){
            val = xo;
            printf("%d\n", val);
            continue;
        }
 
        val = xo;
        anc = get_anc(x, y);
        while(x != anc){
            val = max(val, arr[x] ^ xo);
            x = par[x];
        }
        x = y;
        while(x != anc){
            val = max(val, arr[x] ^ xo);
            x = par[x];
        }
        printf("%d\n", val);
    }
}
 
int main(){
    int test = 1;
  //  freopen("input.txt", "r", stdin);
    cin>>test;
    while(test--){
        solve();
    }
}