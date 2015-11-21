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
ll md=1000000007;

int main() {
	var(ll);
	ll n,r,d;
	ll dp[101][101];
	fr(i,0,101) {
		fr(j,0,101) {
			if(i==0 || j==0) dp[j][i]=0;
			else if(i==1 || j==1) dp[j][i]=1;
			else if(j<i) {
				dp[j][i]=dp[j][i-1];
			}
			else if(j==i) {
				dp[j][i]=(dp[j][i-1]+1)%md;
			}
			else if(j==i+1) {
				dp[j][i]=(dp[j-1][i]*2 -1+md)%md;
			}
			else {
				dp[j][i]=(dp[j-1][i]*2 - dp[j-i-1][i] + md)%md;
			}
		}
	}
	sc("%lld %lld %lld",&n,&r,&d);
	pf("%lld",(dp[n][r]-dp[n][d-1]+md)%md);
	return 0;
}
