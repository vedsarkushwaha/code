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
	var(unsigned ll);
	sc("%llu",&T);
	if((T==0)||((T&(T-1))==0))
		pf("TAK");
	else
		pf("NIE");
	//pf("%llu %llu %llu",T,T-1,T&(T-1));
	return 0;
}