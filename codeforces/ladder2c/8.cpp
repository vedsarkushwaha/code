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

int n,m;
int mat[301][301];
void getNext(int &p, int &q) {
	var(int);
	// return the next number
	// no next number return -1,-1
	mat[p][q]=1;
	if(q==1 && mat[p][q+1]==0) {
		q=q+1;
	}
	else if(q==1 && mat[p][q+1]==1 && p<n) {
		p=p+1;
	}
	else if(q==m && mat[p][q-1]==0) {
		q=q-1;
	}
	else if(q==m && mat[p][q-1]==1 && p<n) {
		p=p+1;
	}
	else if(q<m && mat[p][q+1]==0) {
		q=q+1;
	}
	else if(q>1 && mat[p][q-1]==0) {
		q=q-1;
	}
	else if(p==n && q==m && mat[p][q-1]==1) {
		q=-1;
		p=-1;
	}
	else if(p==n && q==1 && mat[p][q+1]==1) {
		q=-1;
		p=-1;
	}
	else if(1) {
		assert(1==0);
	}
}

int main() {
	var(int);
	vector<vector<pair<int,int> > > opt;
	vector<pair<int,int> > tb;
	sc("%d %d %d",&n,&m,&k);
	int p=1,q=1;

	// while(p!=-1) {
	// 	pf("%d %d\n",p,q);
	// 	getNext(p,q);
	// }
	while(k>1) {
		tb.clear();
		tmp=0;
		while(tmp<2) {
			tb.pb(make_pair(p,q));
			getNext(p,q);
			tmp++;
		}
		opt.pb(tb);
		k--;
	}
	tb.clear();
	while(p!=-1) {
		tb.pb(make_pair(p,q));
		getNext(p,q);
	}
	opt.pb(tb);
	fr(i,0,opt.size()) {
		pf("%d",opt[i].size());
		fr(j,0,opt[i].size()) {
			pf(" %d %d",opt[i][j].first,opt[i][j].second);
		}
		pf("\n");
	}
	return 0;
}
