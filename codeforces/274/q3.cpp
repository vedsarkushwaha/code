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
int main() {
	var(int);
	int N,A,B;
	vector<pair<int,int> > vec;
	sc("%d",&N);
	while(N--) {
		sc("%d %d",&A,&B);
		vec.push_back(pair<int,int>(A,B));
	}
	sort(vec.begin(),vec.end());
	//fr(i,0,vec.size()) {
	//	pf("%d %d\n",vec[i].first,vec[i].second);
	//}
	tmp1=vec[0].second;
	fr(i,1,vec.size()) {
		if(vec[i].second<tmp1)
			tmp1=vec[i].first;
		else
			tmp1=vec[i].second;
	}
	pf("%d\n",tmp1);
	return 0;
}
