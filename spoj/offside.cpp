#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
using namespace std;

int main() {
	var(int);
	vector<int> A,D;
	while(1) {
		A.clear();D.clear();
		sc("%d %d",&tmp1,&tmp2);
		if((tmp1==0)&&(tmp2==0))
			break;
		fr(i,0,tmp1) {
			sc("%d",&tmp);
			A.push_back(tmp);
		}
		fr(i,0,tmp2) {
			sc("%d",&tmp);
			D.push_back(tmp);
		}
		sort(A.begin(),A.end());
		sort(D.begin(),D.end());
		if(A[0]<D[1])
			pf("Y\n");
		else
			pf("N\n");
	}
	return 0;
}