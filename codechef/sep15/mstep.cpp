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
	int T;
	sc("%d",&T);
	while(T--) {
		int N;
		sc("%d",&N);
		vector<pair<int,pair<int,int> > > vec;
		fr(i,0,N) {
			fr(j,0,N) {
				sc("%d",&tmp);
				vec.pb(make_pair(tmp,make_pair(i,j)));
			}
		}
		sort(vec.begin(),vec.end());
		int sm=0;
		fr(i,0,N*N-1) {
			sm+=(abs(vec[i].second.first - vec[i+1].second.first) + abs(vec[i].second.second - vec[i+1].second.second));
		}
		pf("%d\n",sm);
	}
	return 0;
}