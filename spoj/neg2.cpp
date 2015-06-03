#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define sz 10000
using namespace std;
vl mn,lm;
int arr[40];
void fun(ll N) {
	ll i;
	//pf("%lld ",N);
	if(N==0)
		return;
	if(N<0) {
		//pf("en");
		for(i=1;i<40;i+=2) {
			if(lm[i]<=N) {
				arr[i]=1;
				N=N-mn[i];
				break;
			}
		}
	}
	else {
		for(i=0;i<40;i+=2) {
			if(lm[i]>=N) {
				arr[i]=1;
				N=N-mn[i];
				break;
			}
		}
	}
	fun(N);
}
int main() {
	var(ll);
	sc("%lld",&N);
	if(N==0) {
		pf("0");
		return 0;
	}
	fr(i,0,40) {
		tmp=1LL<<i;
		if(i%2!=0)
			tmp*=-1;
		mn.pb(tmp);
	}
	lm.pb(1);lm.pb(-2);
	fr(i,2,40) {
		lm.pb(lm[i-2]+mn[i]);
	}
	fun(N);
	ifr(i,40,-1) {
		if(arr[i]==0 && tmp5==0)
			continue;
		tmp5=1;
		pf("%d",arr[i]);
	}
	return 0;
}