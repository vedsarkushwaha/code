#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,K
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

vector<int> segtree;
vi vec;
void init_seg(int N) {
	segtree.resize(4*N,INT_MIN);
}
void build_seg(int nd, int l, int r) {
	var(int);
	if(l==r)
		segtree[nd]=vec[l];
	else {
		tmp1=2*nd,tmp2=2*nd+1;
		build_seg(tmp1,l,(l+r)/2);
		build_seg(tmp2,(l+r)/2+1,r);
		segtree[nd]=max(segtree[tmp2],segtree[tmp1]);
	}
}
int query(int nd, int l,int r,int i,int j) {
	int p1,p2;
	if(i>r || j<l) {
		return INT_MIN;
	}
	if (l>=i && r<=j)
		return segtree[nd];
	p1=query(2*nd,l,(l+r)/2,i,j);
	p2=query(2*nd+1,(l+r)/2+1,r,i,j);
	if(p1==INT_MIN)
	  return p2;
	if(p2==INT_MIN)
	  return p1;
	return max(p1,p2);
}
int main() {
	var(int);
	sc("%d",&T);
	vec.pb(0);
	fr(i,0,T) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	init_seg(vec.size());
	build_seg(1,1,vec.size());
	sc("%d",&K);
	//pf("%d %d",N,K);
	fr(i,1,T-K+2) {
	  //pf("enter ");	
	  pf("%d ",query(1,1,vec.size(),i,i+K-1));
	}
	return 0;
}
