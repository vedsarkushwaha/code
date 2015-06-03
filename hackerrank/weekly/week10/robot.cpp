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
#define fr(i,m,n) for(i=m;i<n;i++)
#define fri(i,m,n) for(i=m;i>0;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
unsigned ll power(unsigned long long x,unsigned long long y) {
	unsigned ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
ll V[500009];
ll P[500009];
ll dp[500009];
int main() {
	var(ll);
	ll N;
	sc("%lld",&N);
	fr(i,0,N+1) {
		dp[i]=0;
		if(i==0)
			continue;
		sc("%lld",&V[i]);
		sc("%lld",&P[i]);
	}
	P[0]=1;
	fr(i,1,N+2) {
		tmp1=-1;
		tmp2=-1;
		fri(j,i-1,0) {
			if(i==(N+1))
				tmp3=i-j-1;
			else
				tmp3=i-j;
			if(P[j]>=tmp3) {
				if(tmp1<(tmp+dp[j])){
					tmp1=(tmp+dp[j]);
					tmp2=j;
				}
			}
			tmp+=V[j];		
		}
		dp[i]=tmp1;
	}
	pf("%llu",dp[N+1]);
	return 0;
}
