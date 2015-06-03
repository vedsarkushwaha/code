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
struct node {
	unsigned ll x,y;
};
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
bool comp(node x,node y) {
	return x.x<y.x;
}
int main() {
	var(unsigned ll);
	vector<node> vec;
	vector<node>::iterator it;
	node ele;
	unsigned ll N,S,E;
	sc("%llu %llu %llu",&N,&S,&E);
	while(N--) {
		sc("%llu %llu",&tmp1,&tmp3);
		if(tmp1<tmp3)
			continue;
		if(tmp1>=E)
			continue;
		if(tmp3>E)
			tmp3=E;
		ele.x=tmp1-tmp3;ele.y=tmp1+tmp3;
		vec.push_back(ele);
	}
	sort(vec.begin(),vec.end(),comp);
	tmp=0;
	i=S;
	tmp1=0;
	for(it=vec.begin();it!=vec.end();++it) {
		if(i>=E) {
			tmp1=1;
			break;
		}
		if(i<(*it).x) {
			tmp+=((*it).x-i);
			i=(*it).y;
		}
		else if(i<(*it).y) {
			i=(*it).y;
		}
	}
	if(tmp1==0)
		tmp+=(E-i);
	pf("%llu\n",tmp);
	return 0;
}
