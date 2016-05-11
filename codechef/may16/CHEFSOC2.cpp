#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

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

int md=1000000007;

void printVec(vi vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d ",vec[i]);
	}
	pf("\n");
}

int main() {
	var(int);
	int T,M,N,s;
	vi power;
	sc("%d",&T);
	// pf("1");
	// fflush(stdout);
	while(T--) {
		power.clear();
		power.pb(-1);
		sc("%d %d %d",&N,&M,&s);
		fr(i,0,M) {
			sc("%d",&tmp);
			power.pb(tmp);
		}
		// pf("input done\n");
		// fflush(stdout);
		vi jump[1001];
		vi::iterator it;
		jump[s].pb(0);
		// pf("GoingIntoLoop\n");
		// fflush(stdout);
		fr(j,1,M+1) {
			// j is sequence
			// pf("GoingIntoInnerLoop\n");
			// fflush(stdout);
			fr(i,1,N+1) {
				// pf("%d: ",i);
				// printVec(jump[i]);
				// fflush(stdout);
				it=lower_bound(jump[i].begin(),jump[i].end(),j-1);
				if(it!=jump[i].end() && *it==j-1) {
					// pass further
					flag=0;
					if(i+power[j]<=N) {
						jump[i+power[j]].pb(j);
						flag=1;
					}
					if(i-power[j]>=1) {
						jump[i-power[j]].pb(j);
						flag=1;
					}
					if(flag==0) jump[i].pb(M);
				}
			}
		}
		// cnt balls for each monkey
		int monkeyBalls[N+1];
		fr(i,0,N+1) monkeyBalls[i]=0;
		fr(i,1,N+1) {
			int cnt=0;
			fr(j,0,jump[i].size()) if(jump[i][j]==M) cnt++;
			monkeyBalls[i]=cnt;
		}
		fr(i,1,N+1) pf("%d ",monkeyBalls[i]);
		pf("\n");
	}
	return 0;
}