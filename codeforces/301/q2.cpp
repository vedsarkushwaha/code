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
	int n,p,x,y;
	sc("%d %d %d %d %d",&n,&k,&p,&x,&y);
	vi vec;
	fr(i,0,k) {
		sc("%d",&tmp);
		vec.pb(tmp);
		if(tmp<y)
			tmp4++;
	}
	if((n+1)/2 <=tmp4) {
		pf("-1\n");
		return 0;
	}
	tmp5=k-tmp4;
	if(tmp5>=(n+1)/2)
		tmp=0;
	else
		tmp=(n+1)/2 -tmp5;
	tmp1=tmp*y+accumulate(vec.begin(),vec.end(),0)+n-k-tmp;
	// pf("%d %d %d %d\n",tmp4,tmp5,tmp,tmp1);
	if(tmp1>x) {
		pf("-1");
	}
	else {
		fr(i,0,tmp) {
			pf("%d ",y);
		}
		fr(i,0,n-k-tmp)
			pf("1 ");
	}
	return 0;
}