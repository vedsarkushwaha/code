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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
int chk(int num) {
	var(int);
	if(num<2)
		return 0;
	if(num<25) {
		if((num==2)||(num==3))
			return 1;
		if((num%2==0)||(num%3==0))
			return 0;
		return 1;
	}
	if(((num-1)%6!=0)&&((num+1)%6!=0))
		return 0;
	tmp=(int)sqrt(num)+1;
	j=2;
	while(j<=tmp) {
		if(num%j==0)
			return 0;
		j++;
	}
	return 1;
}
int main() {
	var(int);
	int T,N,M;
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&M,&N);
		fr(i,M,N+1) {
			if(chk(i)==1) {
				pf("%d\n",i);
			}
		}
		if(T!=0)
			pf("\n");
	}
	return 0;
}
