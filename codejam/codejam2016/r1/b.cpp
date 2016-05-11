#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cassert>
#include <queue>
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
	int T,tc,N;
	sc("%d",&T);
	// vi vec[100];
	int arr[2501];
	fr(tc,1,T+1) {
		sc("%d",&N);
		fr(i,0,2501) arr[i]=0;
		fr(i,0,N) {
			fr(j,0,2*N-1) {
				sc("%d",&tmp);
				arr[tmp]++;
			}
		}
		vi vec;
		fr(i,0,2501) {
			if(arr[i]%2) vec.pb(i);
		}
		assert(vec.size()==N);
		sort(vec.begin(),vec.end());
		// Case #1: 3 4 6
		pf("Case #%d: ",tc);
		fr(i,0,vec.size()) pf("%d ",vec[i]);
		pf("\n");
	}
	return 0;
}