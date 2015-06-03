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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,tmp4,tmp5
using namespace std;
vector<ll> arr;
int dp[2023][2023];
ll fun(ll i,ll j,ll k) {
	if(dp[i][j]!=0) {
		return dp[i][j];
	}
	else if((i>j)||(i>=arr.size())||(j>=arr.size())||(i<0)||(j<0))
		return 0;
	else if(j-i==1) {
		dp[i][j]=min(arr[i],arr[j])*k+max(arr[i],arr[j])*(k+1);
		return dp[i][j];
	}
	else {
		dp[i][j]=max(fun(i+1,j,k+1)+arr[i]*k,fun(i,j-1,k+1)+arr[j]*k);
		return dp[i][j];
	}
}
		
int main() {
	var(ll);
	ll N;
	sc("%lld",&N);
	fr(i,0,N) {
		sc("%lld",&tmp);
		arr.push_back(tmp);
		dp[i][i]=tmp;
	}
	pf("%lld\n",fun(0,N-1,1));
	/*fr(i,0,N) {
		fr(j,0,N) {
			pf("%d\t",dp[i][j]);
		}
		pf("\n");
	}*/
	return 0;
}
