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
int chk(char ch) {
	var(int);
	if(ch=='0')
		return 2;
	if(ch=='1')
		return 7;
	if(ch=='2')
		return 2;
	if(ch=='3')
		return 3;	
	if(ch=='4')
		return 3;
	if(ch=='5')
		return 4;
	if(ch=='6')
		return 2;
	if(ch=='7')
		return 5;
	if(ch=='8')
		return 1;
	if(ch=='9')
		return 2;
}
int main() {
	var(int);
	char str[10];
	sc("%s",str);
	tmp1=chk(str[0]);
	tmp2=chk(str[1]);
	pf("%d",tmp1*tmp2);
	return 0;
}