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
	int inp[100001],inv[100001];
	while(1) {
		sc("%d",&T);
		if(T==0)
			break;
		fr(i,1,T+1) {
			sc("%d",&inp[i]);
			inv[inp[i]]=i;
		}
		//chk
		tmp3=0;
		fr(i,1,T+1) {
			if(inv[i]!=inp[i]) {
				tmp3=1;
				pf("not ambiguous\n");
				break;
			}
		}
		if(tmp3==0)
			pf("ambiguous\n");
	}
	return 0;
}
