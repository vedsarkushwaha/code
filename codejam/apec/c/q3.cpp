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
#define INT_MAX 10000000
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
int dig[10];
int chk(int N) {
	var(int);
	while(N!=0) {
		if(dig[N%10]==1)
			tmp++;
		else
			return INT_MAX;
		N/=10;
	}
	return tmp;
}
int calc(int N) {
	var(int);
	//pf("%d\n",N);
	tmp=sqrt(N);
	tmp3=chk(N);
	fr(i,2,tmp+1) {
		if(N%i==0) {
			tmp1=calc(N/i);
			tmp2=calc(i);
			//pf("%d %d %d %d\n",tmp1,N/i,tmp2,i);
			tmp3=min(tmp1+tmp2+1,tmp3);
		}
	}
	return tmp3;
}
int main() {
	var(int);
	int T,N;
	sc("%d",&T);
	fr(j,1,T+1) {
		fr(i,0,10)
			sc("%d",&dig[i]);
		sc("%d",&N);
		if((tmp=chk(N))!=INT_MAX)
			pf("Case #%d: %d\n",j,tmp+1);
		else {
			tmp=calc(N);
			if(tmp<INT_MAX)
				pf("Case #%d: %d\n",j,calc(N)+1);
			else
				pf("Case #%d: Impossible \n",j);
		}
	}
	return 0;
}
