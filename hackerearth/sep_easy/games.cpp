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

int main() {
	var(int);
	int N,M,Q;
	sc("%d %d %d",&N,&M,&Q);
	vector<int> vec[N];
	fr(i,0,N) {
		fr(j,0,M) {
			sc("%d",&tmp);
			vec[i].push_back(tmp);
		}
	}
	//sort
	//fr(i,0,N) {
		//sort(vec[i].begin(),vec[i].end());
	//}
	while(Q--) {
		tmp1=INT_MAX;
		fr(i,0,N) {
			sc("%d",&tmp);
			tmp2=upper_bound(vec[i].begin(),vec[i].end(),tmp)-vec[i].begin();
			if(tmp2<tmp1)
				tmp1=tmp2;
		}
		pf("%d\n",tmp1);
	}
	return 0;
}
