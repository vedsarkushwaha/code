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

int main() {
	vl vec;
	var(ll);
	vec.pb(0);
	
	set<ll> st;
	st.insert(0);
	fr(i,1,500001) {
		tmp=vec[i-1]-i;
		if(tmp>0 && st.find(tmp)==st.end()) {
			vec.pb(tmp);
			st.insert(tmp);
		}
		else {
			vec.pb(vec[i-1]+i);
			st.insert(vec[i-1]+i);
		}
	}
	N=0;
	while(1) {
		sc("%lld",&N);
		if(N==-1) {
			break;
		}
		pf("%lld\n",vec[N++]);
	}
	return 0;
}
