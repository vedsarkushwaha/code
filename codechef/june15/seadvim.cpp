#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0,M=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(int);
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&N,&M);
		int mat[N+10][M+10];
		// int numCnt[1001]={0};
		vector<vii> vec(1001);
		fr(i,1,N+1) {
			fr(j,1,M+1) {
				sc("%d",&mat[i][j]);
				// numCnt[mat[i][j]]++;
				vec[mat[i][j]].pb(make_pair(i,j));
			}
		}
		// fr(i,1,1001) {
		// 	assert(numCnt[i]%2==0);
		// }
		// fr(i,1,11) {
		// 	pf("%d:\n",i);
		// 	fr(j,0,vec[i].size()) {
		// 		pf("%d %d\n",vec[i][j].first,vec[i][j].second);
		// 	}
		// 	pf("\n");
		// }
		pf("%d\n",N*M/2);
		fr(i,1,1001) {
			// pf("%d:\n",i);
			fr(j,0,vec[i].size()/2) {
				pf("%d %d %d %d\n",vec[i][j].first,vec[i][j].second,vec[i][j].first,vec[i][j].second);
			}
			// pf("\n");
		}
	}
	return 0;
}