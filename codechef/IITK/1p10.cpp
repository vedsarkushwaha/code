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

int main() {
	int N,Q;
	var(int);
	sc("%d %d",&N,&Q);
	//pf("%d",Q);
	int par[N+1],cnt[N+1],cost[N+1];
	//init
	fr(i,1,N+1) {
		par[i]=i;
		cnt[i]=0;
		cost[i]=0;
	}
	fr(i,1,N) {
		sc("%d %d",&tmp1,&tmp2);
		par[tmp2]=tmp1;
	}
	fr(i,1,N+1) {
		sc("%d ",&tmp);
		cost[i]=tmp;
		if(tmp==0) {
			do {
				cnt[j]+=1;
				j=par[j];
				//pf(" %d ",j);
			}while(par[j]!=j);
		}
	}
	char qq;
	while(Q--) {
		//pf("q");
		sc("%c ",&qq);
		if(qq=='U') {
			sc("%d %d ",&tmp1,&tmp2);
			//change sum and parent
			cost[tmp1]=+tmp2;
			if(cost[tmp1]==0) {
				do {
					cnt[j]+=1;
					j=par[j];
				}while(par[j]!=j);
			}
			if(cost[tmp1]==tmp2) {
				do {
					cnt[j]-=1;
					j=par[j];
				}while(par[j]!=j);
			}
		}
		else {
			sc("%d ",&tmp1);
			//pf(" %d ",tmp1);
			pf("%d\n",cnt[tmp1]);
		}
		//pf("%c %d %d\n",qq,tmp1,tmp2);
	}
	return 0;
}