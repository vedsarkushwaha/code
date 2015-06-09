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
void print(vi vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d ",vec[i]);
	}
}
int main() {
	var(int);
	int n,l,r,x;
	sc("%d %d %d %d",&n,&l,&r,&x);
	vi vec;
	fr(i,0,n) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	vi ps;
	int sum=0,mn=INT_MAX,mx=INT_MIN,cnt=0;
	fr(i,0,(1<<n)) {
		sum=0,mn=INT_MAX,mx=INT_MIN;
		ps.clear();
		fr(j,0,n+1) {
			if(i&(1<<j)) {
				ps.pb(vec[j]);
				sum+=vec[j];
				mn=min(mn,vec[j]);
				mx=max(mx,vec[j]);
			}
		}
		// pf("\n");
		// print(ps);
		// pf("\n");
		if(ps.size()>=2 && mx-mn>=x && sum>=l && sum<=r) {
			cnt++;
		}
	}
	pf("%d\n",cnt);
	return 0;
}
