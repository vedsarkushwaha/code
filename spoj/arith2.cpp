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
	var(ll);
	sc("%lld",&T);
	char ch;
	while(T--) {
		tmp3=0;
		sc("%lld",&tmp);
		while(1) {
			//fflush(stdout);
			sc("%c",&ch);
			if(ch=='=')
				break;
			else if(ch=='+') {
				sc("%lld",&tmp3);
				tmp+=tmp3;
			}
			else if(ch=='-') {
				sc("%lld",&tmp3);
				tmp-=tmp3;
			}
			else if(ch=='*') {
				sc("%lld",&tmp3);
				tmp*=tmp3;
			}
			else if(ch=='/') {
				sc("%lld",&tmp3);
				tmp/=tmp3;
			}
		}
		pf("%lld\n",tmp);
	}
	return 0;
}
