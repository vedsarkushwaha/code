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
	string str;
	cin>>str;
	var(int);
	vector<int> vec;
	tmp1=0;tmp2=0;tmp3=0;
	fr(i,0,str.length()) {
		if(str[i]=='(')
			tmp1++;
		if(str[i]==')')
			tmp2++;
		if(str[i]=='#')
			tmp3++;
	}
	if(tmp2>=tmp1) {
		pf("-1");
		return 0;
	}
	if(tmp1-tmp2<tmp3) {
		pf("-1");
		return 0;
	}
	j=0;k=0;
	fr(i,0,str.length()) {
		if(str[i]=='(')
			j++;
		if(str[i]==')')
			k++;
		if(str[i]=='#') {
			if(k>=j) {
				pf("-1");
				return 0;
			}
			if(tmp3==1) {
				if(j-k>=tmp1-tmp2)
					vec.push_back(tmp1-tmp2);
				else {
					pf("-1");
					return 0;
				}
			}
			else {
				vec.push_back(1);
				tmp3--;
				tmp2++;
				k++;
			}
		}
	}
	fr(i,0,vec.size()) {
		pf("%d\n",vec[i]);
	}
	return 0;
}
