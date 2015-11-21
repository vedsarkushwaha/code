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

ll arr[1000000];
ll lft[1000000];
ll rgt[1000000];

int main() {
	int N;
	var(int);

	sc("%d",&N);
	fr(i,0,N) {
		sc("%lld",arr+i);
	}
	lft[0]=arr[0];
	rgt[N-1]=arr[N-1];
	fr(i,1,N) {
		lft[i]=lft[i-1]+arr[i];
		rgt[N-1-i]=rgt[N-i]+arr[N-1-i];
	}
	// fr(i,0,N) {
	// 	pf("%lld\t%lld\t%lld\n",arr[i],lft[i],rgt[i]);
	// }
	ll sm;
	if(lft[N-1]%3) {
		pf("0");
		return 0;
	}
	else if(lft[N-1]==0) {
		ll tmp5=0;
		fr(i,0,N) if(lft[i]==0) tmp5++;
		tmp5--;
		pf("%lld",(tmp5*(tmp5-1))/2);
		return 0;
	}
	else sm=lft[N-1]/3;
	ll opt=0;
	fr(i,0,N) {
		if(lft[i]==sm) {
			tmp1++;
		}
		else if(lft[i]==sm*2) {
			if(rgt[i+1]==sm) opt+=(tmp1);
		}
	}
	pf("%lld",opt);
	return 0;
}
