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
bool comp(int a,int b) {
	return a>b;
}
int main() {
	var(int);
	sc("%d",&T);
	vector<int> vec;
	fr(j,1,T+1) {
		vec.clear();
		sc("%d %d",&tmp1,&tmp2);
		while(tmp2--) {
			sc("%d",&tmp);
			vec.push_back(tmp);
		}
		sort(vec.begin(),vec.end(),comp);
		tmp=0;
		fr(i,0,vec.size()) {
			tmp+=vec[i];
			if(tmp>=tmp1) {
				tmp2=1;
				break;
			}
		}
		if(tmp2==1)
			pf("Scenario #%d:\n%d\n\n",j,i+1);
		else
			pf("Scenario #%d:\nimpossible\n\n",j);
	}
	return 0;
}
