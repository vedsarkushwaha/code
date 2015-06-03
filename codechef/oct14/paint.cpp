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
#define md 1000000009
using namespace std;
struct node {
	ll num;
	char alpha;
};
bool comp(node a,node b) {
	return a.num<b.num;
}
int main() {
	node nd;
	char ch;
	vector<node> vec;
	vector<node>::iterator it;
	var(ll);
	ll T,N,M;
	sc("%lld",&T);
	while(T--) {
		vec.clear();
		sc("%lld %lld",&N,&M);
		//cin>>N>>M;
		while(M--) {
			sc("\n%c %lld",&ch,&tmp);
			//cin>>ch>>tmp;
			//pf("%c %lld\n",ch,tmp);
			nd.num=tmp;nd.alpha=ch;
			vec.push_back(nd);
		}
		sort(vec.begin(),vec.end(),comp);
		tmp1=1;
		if(vec.size()==1)
			tmp1=1;
		else {
			it=vec.begin();
			tmp2=it->num;
			ch=it->alpha;
			++it;
			while(it!=vec.end()) {
				if(it->alpha==ch) {
					tmp2=it->num;
				}
				else {
					tmp1*=(it->num - tmp2);
					tmp1=tmp1%md;
					ch=it->alpha;
					tmp2=it->num;
				}
				++it;
			}
		}
		pf("%lld\n",tmp1);
	}
	return 0;
}
