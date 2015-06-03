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
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

int main() {
	var(int);
	int a,b,c;
	sc("%d %d %d",&a,&b,&c);
	tmp=a+b+c;
	tmp=max(tmp,a*b*c);
	tmp=max(tmp,a*b+c);
	tmp=max(tmp,a+b+c);
	tmp=max(tmp,a*(b+c));
	tmp=max(tmp,a+(b*c));
	tmp=max(tmp,(a+b)*c);
	pf("%d\n",tmp);
	return 0;
}
