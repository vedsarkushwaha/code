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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
using namespace std;

int main() {
	var(int);
	string str;
	tmp1=0;tmp2=0;tmp3=0;tmp=0;
	sc("%d",&T);
	while(T--) {
		cin>>str;
		//cout<<str;
		if(str=="1/4")
			tmp1++;
		else if(str=="1/2")
			tmp2++;
		else
			tmp3++;
	}
	if(tmp1<=tmp3) {
		tmp=tmp1+(tmp3-tmp1);
		if(tmp2%2==0)
			tmp+=(tmp2/2);
		else
			tmp+=(tmp2/2 + 1);
	}
	else {
		tmp=tmp3;
		tmp1=tmp1-tmp3;
		if(tmp1%2==0) {
			tmp2+=tmp1/2;
			//pf(" %d ",tmp2);
			if(tmp2%2==0)
				tmp+=tmp2/2;
			else
				tmp+=(tmp2/2 +1);
		}
		else {
			tmp2+=tmp1/2;
			tmp+=(tmp2/2 +1);
		}
	}
	pf("%d",tmp+1);
	return 0;
}
