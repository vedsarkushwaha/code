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
int chk(string str) {
	int len=str.length();
	int flag=0;
	int i;
	for(i=1;i<len;i++) {
		if(str[i-1]<str[i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	var(int);
	int T;
	string str,str1;
	sc("%d",&T);
	while(T--) {
		cin>>str;
		if(chk(str))
			cout<<"no answer"<<endl;
		else {
			str1=str;
			next_permutation(str.begin(),str.end());
			if(str==str1)
				cout<<"no answer"<<endl;
			else
			cout<<str<<endl;
		}
	}
	return 0;
}
