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
class comp {
	bool comp(pair<int,int> pr1, pair<int,int> pr2) {
		if(pr1.first==pr1.second) return pr1.second>pr2.second;
		else return pr1.first<pr1.second;
	}
};

int main() {
	var(ll);
	priority_queue<pair<int,int>,vii, comp > pq;
	sc("%d",&N);
	fr(i,0,N) {
		sc("%d",&tmp);
		pq.push(tmp);
	}
	while(!pq.empty()) {
		pf("%d\n",pq.top());
		pq.pop();
	}
	return 0;
}