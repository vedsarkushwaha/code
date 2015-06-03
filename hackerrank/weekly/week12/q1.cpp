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

int main() {
	var(int);
	vector<int> vec;
	int N,P;
	sc("%d",&N);
	while(N--) {
		sc("%d",&tmp);
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
	tmp=0;tmp1=0;tmp2=0;tmp3=0;
	i=0;
	while(1) {
		if(i>=vec.size())
			break;
		tmp=vec[i];
		tmp3++;
		tmp+=4;
		while(vec[i]<tmp && i<vec.size()) {i++;}
	}
	pf("%d",tmp3);
	return 0;
}
