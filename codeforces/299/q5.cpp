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
	int n;
	vector<pair<pair<int,int>,int> > vecx;
	vector<pair<pair<int,int>,int> > vecy;
	sc("%d",&n);
	fr(i,1,n+1) {
		sc("%d %d",&tmp,&tmp1);
		vecx.pb(make_pair(make_pair(tmp,tmp1),i));
		vecy.pb(make_pair(make_pair(tmp1,tmp),i));
	}
	sort(vecx.begin(),vecx.end());
	sort(vecy.begin(),vecy.end());
	pair<int,int> xbest,ybest;
	xbest.first=vecx.back().first.first;
	xbest.second=vecx.back().first.second;
	ybest.first=vecy.back().first.second;
	ybest.second=vecy.back().first.first;
	// pf("xbest=%d %d\n",vecx.back().first.first,vecx.back().first.second);
	// pf("ybest=%d %d\n",vecy.back().first.first,vecy.back().first.second);
	// set<int> st;
	// fr(i,0,vecx.size()) {
	// 	if(vecx[i].first.first==vecx.back().first.first && vecx[i].first.second==vecx.back().first.second)
	// 		st.insert(vecx[i].second);
	// 	else if(vecx[i].first.second>vecx.back().first.second)
	// 		st.insert(vecx[i].second);
	// }
	// set<int>::iterator it;
	// // for(it=st.begin();it!=st.end();++it) {
	// // 	pf("%d ",*it);
	// // }
	// // pf("\n\n");
	// set<int> sty;
	// fr(i,0,vecx.size()) {
	// 	if(vecx[i].first.second==vecy.back().first.first && vecx[i].first.first==vecy.back().first.second)
	// 		sty.insert(vecx[i].second);
	// 	else if(vecx[i].first.first>vecy.back().first.second)
	// 		sty.insert(vecx[i].second);
	// }
	// // for(it=sty.begin();it!=sty.end();++it) {
	// // 	pf("%d ",*it);
	// // }
	// // pf("\n\n");
	vi ans;
	// for(it=st.begin();it!=st.end();++it) {
	// 	if(sty.find(*it)!=sty.end())
	// 		ans.pb(*it);
	// }
	fr(i,0,vecx.size()) {
		if(vecx[i].first.first==xbest.first && vecx[i].first.second==xbest.second)
			ans.pb(vecx[i].second);
		else if(vecx[i].first.first==ybest.first && vecx[i].first.second==ybest.second)
			ans.pb(vecx[i].second);
		else if(vecx[i].first.first<=xbest.first && vecx[i].first.second<=xbest.second)
			continue;
		else if(vecx[i].first.first<=ybest.first && vecx[i].first.second<=ybest.second)
			continue;
		else
			ans.pb(vecx[i].second);
	}
	sort(ans.begin(),ans.end());
	fr(i,0,ans.size()) {
		pf("%d ",ans[i]);
	}
	return 0;
}