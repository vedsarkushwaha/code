#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
ll md=1000000000;

ll arr[4001][4001];
ll dp[2001][2001];

void ncr() {
	ll N,R;
	fr(N,1,4001) {
		fr(R,1,N+1) {
			if(R==1) arr[N][R]=N;
			else if(N==R) arr[N][R]=1;
			else arr[N][R]=(arr[N-1][R-1]+arr[N-1][R])%md;
		}
	}
}
int main() {
	var(ll);
	ll M;
	ncr();
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld",&N,&M);
		fr(i,0,N) {
			fr(j,0,M+1) {
				if(j==0) dp[i][j]=1;
				else if(i==0) dp[i][j]=(dp[i][j-1]+arr[M-1+j][j])%md;
				else dp[i][j]=(dp[i][j-1]+(arr[M-1+j][j]*dp[i-1][j])%md)%md;
			}
		}
		pf("%lld\n",dp[N-1][M]);
	}
	return 0;
}
