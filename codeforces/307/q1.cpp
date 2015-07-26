#include<bits/stdc++.h>
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define sc scanf
#define pf printf
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pb push_back
#define ll long long
using namespace std;

struct node {
	int rt,ind,rk;
};

bool comp (node a, node b) {
	return a.rt>b.rt;
}

bool comp1(node a,node b) {
	return a.ind<b.ind;
}

int main() {
	var(int);
	int n;
	vector<node> vec;
	sc("%d",&n);
	fr(i,0,n) {
		node X;
		sc("%d",&X.rt);
		X.ind=i;
		X.rk=-1;
		vec.pb(X);
	}
	sort(vec.begin(),vec.end(),comp);
	int rank=1;
	i=1;
	vec[0].rk=0;
	while(i<vec.size()) {
		if(vec[i].rt==vec[i-1].rt) vec[i].rk=vec[i-1].rk;
		else vec[i].rk=i;
		i++;
	}
	sort(vec.begin(),vec.end(),comp1);
	fr(i,0,vec.size()) pf("%d ",vec[i].rk+1);
	return 0;
}