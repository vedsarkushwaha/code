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
	int n,x,l,r;
	vector<pair<int,int> > vec;
	sc("%d %d",&n,&x);
	while(n--) {
		sc("%d %d",&l,&r);
		vec.push_back(make_pair(l,r));
	}
	sort(vec.begin(),vec.end());
	j=0;tmp3=0;i=1;
	while(1) {
		if(j>=vec.size())
			break;
		//pf(" %d ",i);
		while(i+x<=vec[j].first) {
			i+=x;
		}
		tmp3+=vec[j].second-i+1;
		//pf(" %d %d %d ",vec[j].second,i,tmp3);
		i=vec[j].second+1;
		j++;
	}
	pf("%d",tmp3);
	return 0;
}
