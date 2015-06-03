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
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
unsigned ll power(unsigned long long x,unsigned long long y) {
	unsigned ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}

int main() {
	int Q;
	var(int);
	sc("%d",&Q);
	while(Q--) {
		sc("%d %d %d",&tmp,&tmp1,&tmp2);
		if(((tmp&1)==1)||((tmp1&1)==1)||((tmp2&1)==1))
			pf("Ashima\n");
		else
			pf("Aishwarya\n");
	}
	return 0;
}
