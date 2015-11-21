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

int main() {
	var(int);
	sc("%d",&N);
	vi vec;
	vii srt;
	vi::iterator it1,it2;
	fr(i,0,N) {
		sc("%d",&tmp);
		vec.pb(tmp);
		srt.pb(make_pair(tmp,i));
	}
	sort(srt.begin(),srt.end());
	int cnt=0;
	it1=vec.begin();
	it2=vec.begin();
	set<pair<int,int> > st;
	set<pair<int,int> >::iterator it;
	st.insert(make_pair(vec[0],0));
	fr(i,0,srt.size()) {
		it=st.find(srt[i]);
		flag=0;
		if(it==st.end()) {
			flag=1;
			// pf("%d %d %d\n",srt[i].first,it1-vec.begin(),it2-vec.begin());
			while(it2!=vec.end() && (*it2)!=srt[i].first) {
				it2++;
				st.insert(make_pair(*it2, it2-vec.begin()));
			}
		}
		else st.erase(it);
		assert(it2!=vec.end());
		if(i==it2-vec.begin()) {
			assert(!flag);
			cnt++;
			it1=it2+1;
			it2=it2+1;
			st.clear();
			st.insert(make_pair(*it1,it1-vec.begin()));
		}
	}
	pf("%d",cnt);
	return 0;
}