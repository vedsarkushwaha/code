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
	string str;
	vector<int> vec;
	cin>>str;
	tmp1=0,tmp2=0,tmp3=0;
	fr(i,0,str.length()) {
		if(str[i]=='(')
			tmp1++;
		else if(str[i]==')')
			tmp2++;
		else
			tmp3++;
		if((tmp2+tmp3)>tmp1) {
			pf("-1");return 0;
		}
	}
	fr(i,0,tmp3-1) {
		//pf("1\n");
		vec.push_back(1);
	}
	//pf("%d",(tmp1-tmp2)-(tmp3-1));
	vec.push_back((tmp1-tmp2)-(tmp3-1));
	//chk
	tmp3=0;j=0;
	fr(i,0,str.length()) {
		if(str[i]=='(')
			tmp3++;
		else if(str[i]==')')
			tmp3--;
		else {
			tmp3=tmp3-vec[j];
			j++;
		}
		if(tmp3<0) {
			pf("-1");
			return 0;
		}
	}
	fr(i,0,vec.size())
		pf("%d\n",vec[i]);
	return 0;
}
