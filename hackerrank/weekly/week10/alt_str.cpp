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
	var(int);
	int T;
	string str;
	sc("%d",&T);
	while(T--) {
		cin>>str;
		tmp=0;
		tmp1=str.length();
		for(i=1;i<tmp1;i++) {
			if(str[i]==str[i-1])
				tmp++;
		}
		pf("%d\n",tmp);
	}
	return 0;
}
