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
	set<int> setm;
	set<int> seta;
	set<int> setb;
	set<int>::iterator it;
	set<int>::iterator fnd;
	var(int);
	fr(i,0,n) {
		sc("%d",&tmp);
		setm.insert(tmp);
	}
	for(it=setm.begin();it!=setm.end();++it) {
		if((fnd=setm.find(a-(*it)))!=setm.end()) {
			seta.insert(*it);
			seta.insert(*fnd);
			setm.erase(it);
		}
		else if((fnd=seta.find(a-(*it)))!=seta.end()) {
			seta.insert(*it);
			setm.erase(it);
		}
		else if((fnd=setb.find(a-(*it)))!=seta.end()) {
			seta.insert(*it);
			setm.erase(it);
		}
	}
	return 0;
}
