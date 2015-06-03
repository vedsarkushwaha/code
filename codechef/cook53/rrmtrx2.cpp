#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define md 10000007
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
using namespace std;
ll mod(ll a) {
	while(a<0) {
		a+=int(md);
	}
	return (a % int(md));
}
int main() {
	var(ll);
	int N,M;
	int mat[100][100];
	sc("%d %d",&N,&M);
	fr(i,0,N) {
		fr(j,0,M) {
			sc("%d",&mat[i][j]);
		}
	}
	tmp3=1;
	fr(j,0,M) {
		tmp2=0;
		fr(i,0,N) {
			tmp2+=mat[i][j];
		}
		while(tmp2<0)
			tmp2+=md;
		tmp3=(tmp3*tmp2)%int(md);
	}
	pf("%lld",tmp3);
	return 0;
}
