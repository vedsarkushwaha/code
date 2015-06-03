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
int chk(char a,char b) {
	var(int);
	tmp1=a-'0';tmp2=b-'0';
	if((tmp1*10+tmp2)<27)
		return 1;
	else
		return 0;
}
ll calc(string str) {
	var(ll);
	vector<ll> dp;
	dp.push_back(1);dp.push_back(1);
	fr(i,1,str.length()) {
		if(str[i]=='0')
			dp.push_back(dp[i-1]);
		else if(str[i-1]=='0')
			dp.push_back(dp[i]);
		else if(chk(str[i-1],str[i]))
			dp.push_back(dp[i]+dp[i-1]);
		else
			dp.push_back(dp[i]);
	}
	//fr(i,0,dp.size()) {
	//	pf("%lld ",dp[i]);
	//}
	//pf("\n");
	return dp.back();
}
int main() {
	var(ll);
	string str;
	while(1) {
		cin>>str;
		if(str=="0")
			break;
		else
			pf("%lld\n",calc(str));
	}
	return 0;
}
