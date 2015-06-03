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

int dist(pair<int,int> p1, pair<int,int> p2) {
	var(int);
	tmp=(p2.first-p1.first)*(p2.first-p1.first);
	tmp1=(p2.second-p1.second)*(p2.second-p1.second);
	return sqrt(tmp+tmp1);
}
pair<int,int> p0;

bool comp(pair<int,int> p1, pair<int,int> p2) {
	var(int);
	tmp1=(p2.first-p0.first)*(p1.second-p0.second);
	tmp2=(p2.second-p0.second)*(p1.first-p0.first);
	if(tmp1!=tmp2)
		return tmp1<=tmp2;
	else {
		tmp4=dist(p0,p2);
		tmp3=dist(p0,p1);
		return tmp3>tmp4;
	}
}

bool chk(pair<int,int> p1, pair<int,int> p2) {
	var(int);
	tmp1=(p2.first-p0.first)*(p1.second-p0.second);
	tmp2=(p2.second-p0.second)*(p1.first-p0.first);
	return tmp1<=tmp2;
}
void print(vii vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d %d\n",vec[i].first,vec[i].second);
	}
}
int main() {
	var(int);
	vii vec;
	pair<int,int> p1,p2,p3;
	sc("%d",&N);
	p0.first=INT_MAX;
	p0.second=INT_MAX;
	int ind=0;
	fr(i,0,N) {
		sc("%d %d",&tmp1,&tmp2);
		vec.pb(make_pair(tmp1,tmp2));
		if(tmp2<p0.second) {
			p0.first=tmp1;
			p0.second=tmp2;
			ind=i;
		}
		else if(tmp2==p0.second && tmp1<p0.first) {
			p0.first=tmp1;
			p0.second=tmp2;
			ind=i;
		}
	}
	// pf("%d %d\n",p0.first,p0.second);
	swap(vec[ind],vec[0]);
	sort(vec.begin()+1,vec.end(),comp);
	fr(i,0,N) pf("%d %d\n",vec[i].first,vec[i].second);
	pf("\n");
	vii stk;
	stk.push_back(vec[0]);
	stk.push_back(vec[1]);
	stk.push_back(vec[2]);
	p1=vec[1];
	p2=vec[2];
	fr(i,3,N) {
		// print(stk);
		pf("\n");
		p0=p1;
		while(!comp(p1,p2)) {
			stk.pop_back();
		}
		stk.push_back(vec[i]);
	}
	// print(stk);
	return 0;
}