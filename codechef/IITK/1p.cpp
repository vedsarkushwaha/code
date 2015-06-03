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

int main() {
	var(int);
	int T,N;
	vector<int> vec;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		tmp1=N;
		while(N--) {
			sc("%d",&tmp);
			vec.push_back(tmp);
		}
		sort(vec.begin(),vec.end());
		pf("%d\n",vec[tmp1-1]);
		vec.clear();
	}	
	return 0;
}
