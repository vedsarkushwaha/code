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
	int n,m;
	sc("%d %d",&n,&m);
	vii vec;
	fr(i,0,m) {
		sc("%d %d",&tmp1,&tmp2);
		vec.pb(make_pair(tmp1,tmp2));
	}
	fr(i,0,vec.size()-1) {
		if(abs(vec[i+1].first-vec[i].first) < abs(vec[i+1].second-vec[i].second)) {
			pf("IMPOSSIBLE\n");
			return 0;
		}
	}
	tmp=0;
	fr(i,0,vec.size()-1) {
		if(abs(vec[i+1].first-vec[i].first)==abs(vec[i+1].second-vec[i].second)) {
			tmp=max(tmp,max(vec[i+1].second,vec[i].second));
		}
		else {
			if(vec[i+1].second>vec[i].second) {
				tmp1=vec[i+1].second-vec[i].second;
				tmp5=(vec[i+1].first-vec[i].first-tmp1)/2;
				tmp=max(tmp,vec[i+1].second+tmp5);
			}
			else {
				tmp1=vec[i].second-vec[i+1].second;
				tmp5=(vec[i+1].first-vec[i].first-tmp1)/2;
				tmp=max(tmp,vec[i].second+tmp5);
			}
		}
	}
	tmp=max(tmp,vec[i].second+(n-vec[i].first));
	tmp=max(tmp,vec[0].second+vec[0].first-1);
	pf("%d\n",tmp);
	return 0;
}