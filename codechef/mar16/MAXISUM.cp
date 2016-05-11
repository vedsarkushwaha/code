#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
using namespace std;

bool debug=0;

int main() {
	var(ll);
	int T,N,K;
	pair<ll,ll> mn,mx;
	sc("%d",&T);
	while(T--) {
		mn.first=INT_MAX;
		mx.first=INT_MIN;
		sc("%d %d",&N,&K);
		vi A,B;
		fr(i,0,N) {
			sc("%lld",&tmp);
			A.pb(tmp);
		}
		fr(i,0,N) {
			sc("%lld",&tmp);
			B.pb(tmp);
			if(mx.first<abs(tmp)) {
				mx.first=abs(tmp);
				mx.second=i;
			}
		}
		if(B[mx.second]>=0) A[mx.second]+=K;
		else A[mx.second]-=K;
		ll sm=0;
		fr(i,0,N) {
			sm+=(ll)A[i]*B[i];
		} 
		pf("%lld\n",sm);
	}
}