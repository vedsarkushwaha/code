#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <map>
#include <iostream>
#include <cstdlib>
#include <climits>

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

int main() {
	var(ll);
	int T,N;
	ll dp[65][10],sm;
	fr(i,1,65) {
		fr(j,0,10) {
			if(i==1 || j==0) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&tmp,&N);
		sm=0;
		fr(i,0,10) sm+=dp[N][i];
		pf("%d %lld\n",tmp,sm);
	}
	return 0;
}