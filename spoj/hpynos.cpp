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
ll nextnum(ll num) {
	var(ll);
	tmp3=0;
	while(num!=0) {
		tmp=num%10;
		tmp3=tmp3+(tmp*tmp);
		num=num/10;
	}
	return tmp3;
}
int main() {
	int arr[1000]={0};
	var(ll);
	sc("%lld",&T);
	tmp3=0;
	while(T>999) {
		//pf("%lld ",T);
		T=nextnum(T);
		tmp3++;
	}
	while(T!=1) {
		//pf("%lld ",T);
		arr[T]=1;
		T=nextnum(T);
		tmp3++;
		if(arr[T]==1) {
			pf("-1");
			return 0;
		}
	}
	pf("%lld",tmp3);
	return 0;
}