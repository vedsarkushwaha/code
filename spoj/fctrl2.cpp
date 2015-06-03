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
vector<int> vec;
void calc(int n) {
	var(int);
	tmp3=0;
	fr(i,2,n+1) {
		fr(j,0,vec.size()) {
			tmp=vec[j]*i+tmp3;
			vec[j]=tmp%10;
			tmp3=tmp/10;
		}
		while(tmp3!=0) {
			vec.push_back(tmp3%10);
			tmp3/=10;
		}
	}
}
void print() {
	int i;
	ifr(i,vec.size()-1,-1) {
		pf("%d",vec[i]);
	}
	pf("\n");
}
int main() {
	var(int);
	int T;
	sc("%d",&T);
	while(T--) {
		vec.clear();
		sc("%d",&tmp);
		vec.push_back(1);
		calc(tmp);
		print();
	}
	return 0;
}
