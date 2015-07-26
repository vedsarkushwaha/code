#include <bits/stdc++.h>
#define sd(n) scanf("%d", &(n))
#define r(i, x, n) for (int i = x, _n = (n); i < _n; ++i)
#define repV(i, v) for (i = v.begin(); i != v.end(); i++)
#define SZ(c) (int)(c).size()
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define VI vector<int>
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mii map<int, int>
#define pii pair<int, int>
#define pip pair<int, pii>
#define F first
#define S second
#define mp make_pair
#define lli long long int
#define CLR(p) memset(p, 0, sizeof(p))
#define SET(p) memset(p, -1, sizeof(p))
#define INF 0x3f3f3f3f
using namespace std;

const int MOD = 1e9+7;
const int MAX = 100010;

int n, x[MAX], y[MAX];
long long cnt;

int main() {
    scanf("%d",&n);
    r(i, 0, n) scanf("%d %d",&x[i],&y[i]);
    double sl1, sl2;
    r(i,0,n) r(j,i+1,n) r(k,j+1,n) if((y[k]-y[i])*(x[j]-x[i])-(x[k]-x[i])*(y[j]-y[i])) cnt++;
    printf("%lld\n", cnt);
    return 0;
}