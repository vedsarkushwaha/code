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
int chk(int n) {
	var(int);
	if(n<2)
		return 0;
	else {
		fr(i,2,n-1) {
			if(n%i==0)
				return 0;
		}
		return 1;
	}
}
int sum(int n) {
	var(int);
	tmp3=0;
	while(n!=0) {
		tmp3+=n%10;
		n=n/10;
	}
	return tmp3;
}
int main() {
	var(int);
	int N,X;
	vector<int> vec;
	sc("%d",&N);
	tmp3=0;
	
	while(N--) {
		sc("%d",&tmp);
		tmp=sum(tmp);
		vec.push_back(chk(tmp));
	}
	tmp3=0;
	reverse(vec.begin(),vec.end());
	fr(i,0,vec.size()) {
		//pf("%d ",vec[i]);
		tmp3+=((1<<i)*vec[i]);
	}
	pf("%d\n",tmp3);
	return 0;
}
