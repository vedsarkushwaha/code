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
#define f(i,m,n) for(i=m;i<n;i++)
#define ull unsigned long long
#define sc scanf
#define pf printf
using namespace std;

void init(ull *a,int len) {
	int i;
	f(i,0,len)
		a[i]=0;
}

void print(ull *a,int len) {
	int i;
	f(i,0,len)
		printf("%llu",a[i]);
}

int main() {
	int T,temp,sum=0;
	sc("%d",&T);
	int flag=0;
	if(T==1) {
		printf("%d\n",1);
		return 0;
	}
	while(T--) {
		sc("%d",&temp);
		if(flag==0) {
			sum=temp;
			flag=1;
		}
		else {
			sum=sum^temp;
		}
	}
	if(sum==0)
		printf("0\n");
	else
		printf("1\n");
	return 0;
}
