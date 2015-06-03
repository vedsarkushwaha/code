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
#define f(i,m,n) for(i=0;i<n;i++)
#define ull unsigned long long
#define sc scanf
#define pf printf
using namespace std;

void init(ull *a,int len) {
	int i;
	f(i,0,len)
		a[i]=0;
}
void print(ull *a,int len) {
	int i;
	f(i,0,len)
		printf("%llu",a[i]);
}

int main() {
	long long a1,a2,b1,b2,c1,c2,d1,d2;
	pair<long long,long long> pa;
	map<long long,long long> ma;
	map<long long,long long>::iterator it;
	sc("%lld%lld",&a1,&a2);sc("%lld%lld",&b1,&b2);sc("%lld%lld",&c1,&c2);
	pa.first=c1+(a1-b1);pa.second=c2+(a2-b2);
	ma.insert(pa);
	pa.first=c1-(a1-b1);pa.second=c2-(a2-b2);
	ma.insert(pa);
	pa.first=a1+(b1-c1);pa.second=a2+(b2-c2);
	ma.insert(pa);
	pa.first=a1-(b1-c1);pa.second=a2-(b2-c2);
	ma.insert(pa);
	for(it=ma.begin();it!=ma.end();++it) {
		printf("%lld %lld\n",(*it).first,(*it).second);
	}	
	return 0;
}
