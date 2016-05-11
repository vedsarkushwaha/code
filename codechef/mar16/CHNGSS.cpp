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
#include <cassert>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,l=0,tmp1,tmp2,tmp3,tmp
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
using namespace std;

int getRemaining(int sum, int sqr) {
	return sum%(sqr*sqr);
}

void printMat(int **arr, int n, int m) {
	var(int);
	fr(i,1,n+1) {
		fr(j,1,m+1) {
			pf("%d ",arr[i][j]);
		}
		pf("\n");
	}
}

int main() {
	var(ll);
	ll n,m,c;
	sc("%lld %lld %lld",&n,&m,&C);
	ll block = (n*m)/C;
	ll sqr = sqrt(block);
	int sum,C;
	int **arr;
	i=1;j=1;
	while(i<=n) {
		while(j<=m) {
			printf("2 %d %d %d %d\n",i,min(i+sqr-1,n),j,min(j+sqr-1,m));
			fflush(stdout);
			sc("%d",&sum);
			fr(k,i,min(i+sqr-1,n)) {
				fr(l,j,min(j+sqr-1,m)) {
					arr[k][l]=sum/(sqr*sqr);
				}
			}
			arr[k-1][l-1]+=getRemaining(sum,sqr);
			i+=sqr;
			j+=sqr;
		}
	}
	printMat(arr,n,m);
	return 0;
}