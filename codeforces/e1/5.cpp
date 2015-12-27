#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int dp[31][31][51];

int fun(int N,int M, int K) {
	var(int);
	if(K==0 || N*M==K) {
		dp[N][M][K]=0;
		return 0;
	}
	
	if(dp[N][M][K]!=-1) return dp[N][M][K];
	pf("N=%d M=%d K=%d\n",N,M,K);

	int cost=INT_MAX-10;
	assert(N!=0 && M!=0);
	fr(i,1,M) {
		fr(j,0,K+1) {
			cost=min(cost, fun(N,i,j) + N*N + fun(N,M-i,K-j));
		}
	}

	fr(i,1,N) {
		fr(j,0,K+1) {
			cost=min(cost, fun(i,M,j) + M*M + fun(N-i,M,K-j));
		}
	}
	dp[N][M][K]=cost;
	return cost;
}

int main() {
	var(int);
	int N,M,K,T;
	sc("%d",&T);
	fr(i,0,31) fr(j,0,31) fr(k,0,51) dp[i][j][k]=-1;
	while(T--) {
		sc("%d %d %d",&N,&M,&K);
		pf("%d\n",fun(N,M,K));
	}
	return 0;
}