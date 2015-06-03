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
#include<numeric>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

vector<ll> vec[100001];
ll calc[100001];
ll rem_node[100001];
vector<ll> w,nw;
ll sum(ll x) {
	ll i;
	calc[x]=1;
	fr(i,0,vec[x].size()) {
		if((calc[vec[x][i]]!=1)&&(rem_node[vec[x][i]]!=1)) {
			w[x]+=sum(vec[x][i]);
		}
	}
	return w[x];
}
void init(ll *a,ll N) {
	ll i;
	fr(i,1,N+1)
		a[i]=0;
}
void remv_node(ll x) {
	ll i;
	calc[x]=1;
	if(rem_node[x]==1) {
		fr(i,0,vec[x].size()) {
			if(calc[vec[x][i]]!=1)
				rem_node[vec[x][i]]=1;
		}
	}
	else {
		fr(i,0,vec[x].size()) {
			if(calc[vec[x][i]]!=1) {
				remv_node(vec[x][i]);
			}
		}
	}
}
int main() {
	vector<ll>::iterator it;
	var(ll);
	ll N,K,sm;
	sc("%lld %lld",&N,&K);
	w.push_back(0);
	nw.push_back(0);
	fr(i,1,N+1) {
		sc("%lld",&tmp);
		nw.push_back(tmp);
	}
	fr(i,1,N) {
		sc("%lld %lld",&tmp1,&tmp2);
		vec[tmp1].push_back(tmp2);
		vec[tmp2].push_back(tmp1);
	}
	tmp=N;
	if(tmp<K)
		K=tmp;
	while(K--) {
		init(calc,N);
		w=nw;
		sum(1);
		tmp1=INT_MAX;
		fr(i,1,w.size()) {
			if((tmp1>w.at(i))&&(rem_node[i]!=1)) {
				tmp1=w.at(i);
				tmp2=i;
			}
		}
		if(w[tmp2]>=0)
			break;
		init(calc,N);
		rem_node[tmp2]=1;
		if(tmp2==1) {
			pf("0\n");
			return 0;
		}
		remv_node(1);
	}
	init(calc,N);
	w=nw;
	sum(1);
	pf("%lld\n",w[1]);	
	return 0;
}
