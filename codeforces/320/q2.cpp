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

bool comp(pair<int,pair<int,int> >a, pair<int,pair<int,int> >b) {
	return a.first>b.first;
}
int main() {
	var(int);
	int n;
	sc("%d",&n);
	vector<pair<int,pair<int,int> > >vec;
	fr(i,2,2*n+1) {
		fr(j,1,i) {
			sc("%d",&tmp);
			// pf("%d ",tmp);
			vec.pb(make_pair(tmp,make_pair(i,j)));
		}
		// pf("\n");
	}
	sort(vec.begin(),vec.end(),comp);
	set<int> st;
	int arr[2*n+1];
	fr(i,0,vec.size()) {
		tmp4=vec[i].second.first;
		tmp5=vec[i].second.second;
		if(st.find(tmp4)!=st.end() || st.find(tmp5)!=st.end()) continue;
		tmp1=vec[i].second.first;
		tmp2=vec[i].second.second;
		arr[tmp1]=tmp2;
		arr[tmp2]=tmp1;
		st.insert(tmp1);
		st.insert(tmp2);
		// printf("%d %d %d\n",vec[i].first,tmp1,tmp2);
	}
	fr(i,1,2*n+1) pf("%d ",arr[i]);
	return 0;
}
