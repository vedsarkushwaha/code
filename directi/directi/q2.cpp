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

int N;
int visit[30000];
int tmpvisit[30000];
int val[30000];
vector<int> vec[30000];
int child;
int chk(int node,int ndval) {
	var(int);
	fr(i,0,vec[node].size()) {
		if(tmpvisit[vec[node][i]]==1)
			continue;
		if(val[ vec[node].at(i) ]!=ndval)
			return 0;
		tmpvisit[vec[node][i]]=1;
		//child++;
		if(chk(vec[node][i],ndval)==0)
			return 0;
	}
	return 1;
}
int dfs() {
	var(int);
	tmp3=0;
	fr(i,0,N) {
		child=1;
		//copy vsit to tmpvisit
		visit[i]=1;
		tmpvisit[i]=1;
		if((tmp=chk(i,val[i]))!=0) {
			tmp3++;
			//pf("%d %d\n",i,tmp);
		}
	}
	return tmp3;
	//return the total sum
}	
int main() {
	var(int);
	sc("%d",&N);
	fr(i,0,N) {
		sc("%d",&val[i]);
	}
	fr(i,0,N-1) {
		sc("%d %d",&tmp1,&tmp2);
		vec[tmp1].push_back(tmp2);
		vec[tmp2].push_back(tmp1);
	}
	pf("%d",dfs());
		
	return 0;
}
