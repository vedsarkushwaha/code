#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define orta (bas + son >> 1)
#define sag (k + k + 1)
#define sol (k + k)
#define endl '\n'
#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)
#define mp make_pair
#define nd second
#define st first
#define type(x) __typeof(x.begin())

typedef pair < int ,int > pii;

typedef long long ll;

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 2e5 + 5;

int n, a[N], b[N];
map< int , int > h;

int main() {

	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b+1, b+n+1);
	int c = 0, ans = 0;
	FOR(i, 1, n) {
		if(!h[b[i]]++) c++;		
		if(!--h[a[i]]) c--;	
		if(!c) ans++;
	}
	cout << ans << endl;

	return 0;
}