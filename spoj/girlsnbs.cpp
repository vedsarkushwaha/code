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
	var(double);
	while(1) {
		sc("%lf %lf",&tmp1,&tmp2);
		if((tmp1==-1)&&(tmp2==-1))
			break;
		pf("%.0lf\n",max(ceil(tmp1/(tmp2+1)),ceil(tmp2/(tmp1+1))));
	}
	return 0;
}
