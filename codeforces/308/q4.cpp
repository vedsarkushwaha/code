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

int main() {
	var(ll);
	ll n;
	sc("%lld",&n);
	vll inp;
	fr(i,0,n) {
		sc("%lld %lld",&tmp1,&tmp2);
		inp.pb(make_pair(tmp1,tmp2));
	}
	ll cnt=0;
	fr(i,0,n) {
		map<double,ll> mp;
		map<double,ll>::iterator it;
		fr(j,i+1,n) {
			double slop=(double)inp[i].first/inp[i].second;
			it=mp.find(slop);
			if(it!=mp.end()) it->second++;
			else mp.insert(pair<double,ll>(slop,1));
		}
		tmp=1;
		for(it=mp.begin();it!=mp.end();++it) tmp=(tmp*(it->second));
		if(mp.size()>=2) cnt+=tmp;
	}
	pf("%lld",cnt);
	return 0;
}