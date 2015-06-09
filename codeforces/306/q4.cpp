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
void fun(int st,int K) {
	var(int);
	fr(i,st+1,st+K) {
		pf("%d %d\n",st,i);
	}
	fr(i,st+1,st+K) {
		fr(j,i+1,st+K) {
			assert(i!=j);
			if(st%2) {
				if(i%2==0 && j==i+1) continue;
			}
			else {
				if(i%2 && j==i+1) continue;
			}
			pf("%d %d\n",i,j);
		}
	}
	fr(i,st+1,st+K) {
		pf("%d %d\n",i,st+K);
		pf("%d %d\n",i,st+K+1);
	}
	pf("%d %d\n",st+K,st+K+1);
}
int main() {
	var(int);;
	sc("%d",&k);
	int v=2*k+4,e=(k*v)/2;
	assert(v/2+1==k+3);
	if(k%2==0) {
		pf("NO\n");
		return 0;
	}
	pf("YES\n");
	if(k==1) {
		pf("2 1\n");
		pf("1 2\n");
		return 0;
	}
	pf("%d %d\n",v,e);
	fun(1,k);
	pf("1 %d\n",k+3);
	fun(k+3,k);
	return 0;
}