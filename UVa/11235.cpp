#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T,N,Q
#define push_back pb
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pii>
using namespace std;
vii segt;
vi inp;
void init(int n) {
	segt.resize(4*n,0);
}
void build(int node,int l,int r) {
	if(l==r)
		segt[node]=make_pair(inp[l],1);
	else {
		tmp1=2*node,tmp2=2*node+1;
		build(tmp1,l,(l+r)/2);
		build(tmp2,(l+r)/2 + 1,r);
		if(segt[tmp1].first==segt[tmp2].first)
			segt[node]=make_pair(segt[tmp1].first,segt[tmp1].second+segt[tmp2].second);
		else {
			segt[node]=make_pair(segt[tmp1].second>segt
	}
}
void query(int node,int l,int r,int L,int R) {
}
int main() {
	var(x);
	sc("%d %d",&N,&Q);
	inp.pb(0);
	fr(i,1,N) {
		sc("%d",&tmp);
		inp.pb(tmp);
	}
	fr(i,0,Q) {
		sc("%d %d",&tmp1,&tmp2);
		//get the answer
	}
	sc("%d",&tmp);
	return 0;
}
