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
int pri[20]={2,3,5,7,11,13,17,19,23,29,31,37};
int prm(int x) {
	int i;
	for(i=0;i<14;i++)
		if(pri[i]==x)
			return 1;
	return 0;
}
int main() {
	int T,N,j,i,temp;
	ull sum;
	sc("%d",&T);
	while(T--) {
		sum=1;
		sc("%d",&N);
		f(i,2,N) {
			if(prm(i)) {
				temp=(int)(log10(N)/log10(i));
				sum*=(ull)pow(i,temp);
				//cout<<sum<<endl;
			}
		}
		pf("%llu\n",sum);
	}
	return 0;
}
