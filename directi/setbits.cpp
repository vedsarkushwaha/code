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
int arr[10000001];
int cnt[16];
int conv(int a,int b,int c,int d) {
	return a*8+b*4+c*2+d*1;
}
void init() {
	var(int);
	fr(i,0,10000001)
		arr[i]=0;
	fr(i,0,16)
		cnt[i]=0;
}
int main() {
	var(int);
	int T,N;
	sc("%d",&T);
	while(T--) {
		init();
		sc("%d",&N);
		while(N--) {
			sc("%d %d",&tmp1,&tmp2);
			arr[tmp1]++;arr[tmp2]++;
		}
		tmp=0;
		fr(i,1,101) {
			if(arr[i]%2==1)
				if(tmp==0)
					tmp=1;
				else
					tmp=0;
			arr[i]=tmp;
		}
		fr(i,1,101)
			pf("%d",arr[i]);
		pf("\n");
		fr(i,1,26) {
			cnt[conv(arr[(4*(i-1))+1],arr[(4*(i-1))+2],arr[(4*(i-1))+3],arr[(4*(i-1))]+4)]++;
		}
		fr(i,0,16)
			pf("%d ",cnt[i]);
		pf("\n");
	}
	return 0;
}