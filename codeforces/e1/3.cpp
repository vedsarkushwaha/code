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
	var(int);
	long double t1,t2,t3;
	int N;
	sc("%d",&N);
	// cin>>N;
	vector<pair<long double,int> > vec;
	fr(i,0,N) {
		sc("%Lf %Lf",&t1,&t2);
		// cin>>t1>>t2;
		if(t2<0.0) vec.pb(make_pair((atan2(t2,t1)+2*M_PI),i+1));
		else vec.pb(make_pair(atan2(t2,t1),i+1));
	}
	sort(vec.begin(),vec.end());
	// fr(i,0,vec.size()) {
	// 	pf("%.14Lf %d\n",vec[i].first,vec[i].second);
	// }
	// pf("\n"); 
	long double ans=10.0;
	int id1=-1;
	fr(i,0,vec.size()-1) {
		t1=vec[i+1].first-vec[i].first;
		if(ans>t1) {
			ans=t1;
			id1=i;
		}
	}
	assert(id1!=-1);
	if(ans>vec[0].first-vec[i].first+(2*M_PI)) {
		// cout<<vec[0].second<<" "<<vec[i].second;
		pf("%d %d",vec[0].second,vec[i].second);
	}
	else {
		// cout<<vec[id1].second<<" "<<vec[id1+1].second;
		pf("%d %d",vec[id1].second,vec[id1+1].second);
	}
	return 0;
}