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
struct node {
	int l,r;
};

vector<node> segtree;
vi vec;
void init_seg(int N) {
	node tmp;
	tmp.l=0,tmp.r=0;
	segtree.resize(4*N,tmp);
}
void build_seg(int nd, int l, int r) {
	var(int);
	if(l==r)
		return;
	else {
		tmp1=2*nd,tmp2=2*nd+1;
		build_seg(tmp1,l,(l+r)/2);
		build_seg(tmp2,(l+r)/2+1,r);
		segtree[nd].l=segtree[tmp1].l+segtree[tmp2].l;
		segtree[nd].r=segtree[tmp1].r+segtree[tmp2].r;
	}
}
node update(int nd, int l,int r,int i,int j) {
	node p1,p2;
	if(i>r || j<l) {
		p1.bs=p1.pr=p1.su=p1.sm=INT_MIN;
		return p1;
	}
	if (l>=i && r<=j)
		return segtree[nd];
	p1=query(2*nd,l,(l+r)/2,i,j);
	p2=query(2*nd+1,(l+r)/2+1,r,i,j);
	if(p1.bs==INT_MIN)
		return p2;
	if(p2.bs==INT_MIN)
		return p1;
	p1.bs=max(p1.su+p2.pr,max(p1.bs,p2.bs)),p1.su=max(p2.su,p2.sm+p1.su),p1.pr=max(p1.pr,p1.sm+p2.pr),p1.sm=p1.sm+p2.sm;
	return p1;
}
int main() {
	var(int);
	T=10;
	vec.pb(0);
	fr(i,1,T+1) {
		sc("%d",&tmp);
		init_seg(tmp);
		fr(j,1,tmp+1) {
			sc("%c",&ch);
			if(ch=='(') {
				segtree[j].l=1;
				segtree[j].r=0;
			}
			else {
				segtree[j].l=0;
				segtree[j].r=1;	
			}
		}
	}
	build_seg(1,1,tmp);
	sc("%d",&N);
	while(N--) {
		sc("%d",&tmp1);
		if(tmp1==0)
			//check
		else
			//update segtree
	}
	return 0;
}