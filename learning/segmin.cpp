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
vi segtree;
void init_seg(int N) {
	segtree.resize(4*N,0);
}
void build_seg(vi vec, int nd, int l, int r) {
	var(int);
	if(l==r)
		segtree[nd]=vec[l];
	else {
		tmp1=2*nd,tmp2=2*nd+1;
		build_seg(vec, tmp1,l,(l+r)/2);
		build_seg(vec, tmp2,(l+r)/2+1,r);
		tmp1=segtree[tmp1],tmp2=segtree[tmp2];
		segtree[nd]=tmp1+tmp2;
	}
}
int query(vi vec, int nd, int l,int r,int i,int j) {
	if(i>r || j<l)
		return -1;
	if (l>=i && r<=j)
		return segtree[nd];
	int p1=query(vec,2*nd,l,(l+r)/2,i,j);
	int p2=query(vec,2*nd+1,(l+r)/2+1,r,i,j);
	if(p1==-1)
		return p2;
	if(p2==-1)
		return p1;
	return p1+p2;
}
int main() {
	var(int);
	vi vec;
	sc("%d",&T);
	vec.pb(0);
	while(T--) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	fr(i,1,vec.size())
		pf("%d ",vec[i]);
	init_seg(vec.size());
	build_seg(vec,1,1,vec.size());
	sc("%d",&N);
	while(N--) {
		sc("%d %d",&tmp1,&tmp2);
		pf("%d\n",query(vec,1,1,vec.size(),tmp1,tmp2));
	}
	return 0;
}
