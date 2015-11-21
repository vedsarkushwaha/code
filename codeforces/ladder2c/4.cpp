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

bool comp(pair<ll,ll> a, pair<ll,ll> b) {
	return a.second>b.second;
}

int main() {
	var(int);
	int N;
	ll arr[100001]={0};
	sc("%d",&N);
	fr(i,0,N) {
		cin>>tmp;
		arr[tmp]+=1;
	}
	ll dp[100001];
	dp[0]=0;
	dp[1]=arr[1];
	tmp=1;
	fr(i,2,100001) {
		if(i-1==tmp) {
			if(dp[i-2]+arr[i]*i > dp[i-1]) {
				dp[i]=dp[i-2]+arr[i]*i;
				tmp=i;
			}
			else {
				dp[i]=dp[i-1];
				tmp=i-1;
			}
		}
		else {
			dp[i]=dp[i-1]+arr[i]*i;
			tmp=i;
		}
		// cout<<dp[i]<<endl;
	}
	cout<<dp[i-1];
	return 0;
}