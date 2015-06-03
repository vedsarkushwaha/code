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
int N;
int mod(int a) {
	if(a<0)
		return a+N;
	else if(a>(N-1))
		return a-N;
	else
		return a;
}
int main() {
	int M;
	var(int);
	int arr[1000000];
	char ch;
	sc("%d%d",&N,&M);
	fr(i,0,N)
		sc("%d",&arr[i]);
	fr(i,0,M) {
		sc("\n%c %d",&ch,&tmp1);
		//pf(" %c%d ",ch,tmp1);
		if(ch=='R') {
			pf("%d\n",arr[mod(mod(tmp+tmp1)-1)]);
		}
		else if(ch=='C') {
			tmp=(tmp+tmp1);
			tmp=mod(tmp);
			//pf("CR");
		}
		else if(ch=='A') {
			tmp=tmp-tmp1;
			tmp=mod(tmp);
			//pf("A");
		}
	}
	return 0;
}
