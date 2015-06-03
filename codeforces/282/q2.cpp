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

int main() {
	var(int);
	sc("%d %d",&tmp1,&tmp2);
	tmp3=0;
	if(tmp1==tmp2)
		pf("infinity");
	else if(tmp2>tmp1)
		pf("0");
	else if(tmp2==0) {
		fr(i,1,tmp1+1) {
			if(tmp1%i==0)
				tmp3++;
		}
		pf("%d",tmp3);
	}
	else if(tmp1==0)
		pf("0");
	else {
		i=1;
		while(1) {
			if(tmp1%i==tmp2) {
				break;
			}
			i++;
		}
		//pf("%d",tmp3);
		while(i<tmp1) {
			if(tmp1%i==0)
				tmp3++;
			i+=
	}
	
	return 0;
}
