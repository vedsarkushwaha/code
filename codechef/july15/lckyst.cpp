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

int main() {
	var(int);
	sc("%d",&N);
	while(N--) {
		sc("%d",&tmp);
		int cnt=0;
		ll num=tmp;
		while(tmp%10==0) {
			tmp=tmp/10;
		}
		while(tmp%5==0) {
			tmp=tmp/5;
			cnt++;
		}
		cnt=(cnt+1)/2;
		while(cnt--) {
			num*=4;
		}
		pf("%lld\n",num);
	}
	return 0;
}
