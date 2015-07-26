#include <bits/stdc++.h>
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
	ll w,m;
	sc("%lld %lld",&w,&m);
	vl pw;
	set<ll> st;
	vl temp;
	set<ll>::iterator it;
	
	pw.pb(1);
	pw.pb(w);
	fr(i,2,100) {
		pw.pb(pw.back()*w);
		if(pw.back()>m) break;
	}
	fr(i,0,pw.size()) {
		temp.clear();
		it=st.begin();
		while(it!=st.end()) {
			temp.pb(pw[i]+(*it));
			++it;
		}
		st.insert(pw[i]);
		fr(j,0,temp.size()) st.insert(temp[j]);
	}
	if(st.find(m)!=st.end()) {
		pf("YES\n");
		return 0;
	}
	for(it=st.begin();it!=st.end();it++) {
		if(st.find(m+(*it))!=st.end()) {
			pf("YES\n");
			return 0;
		}
	}
	pf("NO\n");
	return 0;
}