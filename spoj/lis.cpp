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
	var(int);
	int N;
	sc("%d",&N);
	vector<int> vec,lis;
	while(N--) {
		sc("%d",&tmp);
		vec.push_back(tmp);
	}
	lis.push_back(1);
	fr(i,1,vec.size()) {
		tmp2=0;
		fr(j,0,i) {
			if(vec[j]<vec[i]) {
				tmp2=max(tmp2,lis[j]);
			}
		}
		lis.push_back(tmp2+1);
	}
	pf("%d",*max_element(lis.begin(),lis.end()));
	//fr(i,0,lis.size())
		//pf("%d ",lis[i]);
	return 0;
}
