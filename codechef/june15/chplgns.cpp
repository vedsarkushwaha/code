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
	int cnt,totalPoints=0;
	vector<pair<pair<int,int>,int> > inp;
	vector<int> ans;
	sc("%d",&T);
	while(T--) {
		inp.clear();
		ans.clear();
		cnt=0;
		sc("%d",&N);
		fr(i,0,N) {
			sc("%d",&Q);
			fr(j,0,Q) {
				totalPoints++;
				sc("%d %d",&tmp1,&tmp2);
				inp.pb(make_pair(make_pair(tmp1,tmp2),i));	
			}
			ans.pb(-1);
		}
		sort(inp.begin(),inp.end());

		fr(i,0,totalPoints) {
			// pf("Point Index = %d value=%d\n",i,inp[i].first.first);
			if(ans[inp[i].second]==-1) {
				// pf("Point Inserted = %d value=%d\n\n",i,inp[i].first.first);
				ans[inp[i].second]=N-cnt-1;
				cnt++;
			}
		}
		fr(i,0,N) {
			pf("%d ",ans[i]);
		}
		pf("\n");
	}
	return 0;
}
