#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <map>

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

void stockSpan(vector<int> &input, vector<int> &fromLeft,bool ck) {
	var(int);
	stack<pair<int,int> > stk;
	// from left
	stk.push(make_pair(input[0],1));
	fromLeft.pb(1);
	fr(i,1,input.size()) {
		int sum=1;
		while(!stk.empty() && (stk.top().first<input[i] || (stk.top().first==input[i])*ck)) {
			sum+=stk.top().second;
			stk.pop();
		}
		stk.push(make_pair(input[i],sum));
		fromLeft.pb(sum);
	}
}

void printVec(vi &vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d ",vec[i]);
	}
}

void printVecP(vii &vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d %d\n",vec[i].first,vec[i].second);
	}
}

int main() {
	var(int);
	int N,M;
	vi vec,lft,rgt;
	sc("%d %d",&N,&M);
	fr(i,0,N) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	// precompute
	stockSpan(vec,lft,0);
	reverse(vec.begin(),vec.end());
	stockSpan(vec,rgt,1);
	reverse(rgt.begin(),rgt.end());
	reverse(vec.begin(),vec.end());
	map<int,int> mp;
	map<int,int>::iterator it;
	fr(i,0,vec.size()) {
		if(mp.find(vec[i])!=mp.end()) mp[vec[i]]+=lft[i]*rgt[i];
		else mp[vec[i]]=lft[i]*rgt[i];
	}
	vi finVec,finFreq;
	for(it=mp.begin();it!=mp.end();it++) {
		finVec.pb(it->first);
		if(finVec.size()==0) {
			finFreq.pb(it->second);
		}
		else {
			finFreq.pb(it->second+finFreq.back());
		}
	}
	// printVecP(finVec);
	// pf("\n");
	char ch,pl;
	fr(i,0,M) {
		sc("\n%c %d %c",&ch,&tmp,&pl);
		int sm=0;
		if(ch=='<') {
			// for(it=mp.begin();it!=mp.end();++it) {
			// 	if(it->first < tmp) sm+=it->second;
			// }
		}
		else if(ch=='>') {
			// for(it=mp.begin();it!=mp.end();++it) {
			// 	if(it->first > tmp) sm+=it->second;
			// }
			tmp5=upper_bound(finVec.begin(),finVec.end(),tmp)-finVec.begin();
			
		}
		else if(ch=='=') {
			for(it=mp.begin();it!=mp.end();++it) {
				if(it->first == tmp) sm+=it->second;
			}
		}
		else pf("Wrong Input");
		if(sm%2) pf("%c",pl);
		else {
			if(pl=='C') pf("D");
			else pf("C");
		}
	}
	return 0;
}