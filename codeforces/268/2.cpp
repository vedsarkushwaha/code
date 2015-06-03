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
struct pr {
	int st,et;
};
int chk(pr Z,pr X,int x) {
	if((Z.st>=(X.st+x)) && (Z.st<=(X.et+x)))
		return 1;
	else if((Z.et>=(X.st+x)) && (Z.et<=(X.et+x)))
		return 1;
	else
		return 0;
}
int main() {
	int p,q,l,r;
	var(int);
	sc("%d %d %d %d",&p,&q,&l,&r);
	pr Z[p];pr X[q];
	fr(i,0,p) {
		sc("%d %d",&tmp,&tmp1);
		Z[i].st=tmp;
		Z[i].et=tmp1;
	}
	fr(i,0,q) {
		sc("%d %d",&tmp,&tmp1);
		X[i].st=tmp;
		X[i].et=tmp1;
	}
	unsigned ll cnt=0;
	fr(i,l,r+1) {
		tmp1=0;
		fr(j,0,p) {
			fr(k,0,q) {
				if(chk(Z[j],X[k],i)==1) {
					if(tmp1==0) {
						pf("%d\n",i);
						cnt++;
					}
					tmp1=1;
					//break;
					//pf(" %d ",i);
				}
			}
			//if(tmp1==1)
				//break;
		}
	}
	pf("%llu\n",cnt);
	return 0;
}
