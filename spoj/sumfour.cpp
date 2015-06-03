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
using namespace std;

int main() {
	var(int);
	sc("%d",&N);
	vi a,b,c,d,e,f;
	vi::iterator vit1,vit2;
	map<int,int> mp1,mp2;
	map<int,int>::iterator it,it1;
	pair<map<int,int>::iterator,bool> pr;
	fr(i,0,N) {
		sc("%d %d %d %d",&tmp1,&tmp2,&tmp3,&tmp4);
		a.pb(tmp1),b.pb(tmp2),c.pb(tmp3),d.pb(tmp4);
	}
	fr(i,0,N)
		fr(j,0,N) {
			tmp=a[i]+b[j];
			e.pb(tmp);
			tmp=c[i]+d[j];
			f.pb(-1*tmp);
		}
	sort(e.begin(),e.end());
	sort(f.begin(),f.end());
	e.pb(INT_MAX);f.pb(INT_MAX);
	i=0;
	while(i<N*N) {
		tmp4=0;
		tmp=e[i];
		while(i<N*N && e[i]==tmp) {i++,tmp4++;}
		vit1=lower_bound(f.begin(),f.end(),tmp);
		if(*vit1!=INT_MAX) {
			vit2=upper_bound(f.begin(),f.end(),tmp);
			tmp5+=((vit2-vit1)*tmp4);
		}
	}
	pf("%d",tmp5);
	return 0;
}