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
	int N,P,lst;
	string str;
	sc("%d %d",&N,&P);
	cin>>str;
	tmp=str.length();
	if(tmp%2==0) {
		tmp1=(tmp/2)-1;
		tmp2=tmp/2;
	}
	else {
		tmp1=tmp/2;
		tmp2=tmp/2;
	}
	tmp3=0;
	ifr(i,P-1,-1) {
		j=(tmp1-i)+tmp2;
		if(str[i]!=str[j]) {
			k=mod(str[i]-str[j]);
			tmp3+=(k>26-k)?(26-k):(k);
			lst=i;
		}
	}
	if(tmp3!=0)
		tmp3+=(P-lst);
	fr(i,lst,tmp) {
		
	return 0;
}
