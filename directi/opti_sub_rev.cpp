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
	int T,flag;
	string str,astr;
	sc("%d",&T);
	while(T--) {
		flag=0;
		cin>>str;
		tmp1=str.find('b');
		if(tmp1==string::npos)
			pf("0,0\n");
		else {
			tmp=str.length();
			ifr(i,tmp,0) {
				astr.clear();
				fr(j,0,i)
					astr+='a';
				tmp2=str.find(astr,tmp1);
				if(tmp2!=string::npos) {
					flag=1;
					//find all occurrance and print the farthest occurrance
					while(tmp2!=string::npos) {
						tmp3=tmp2;
						tmp2=str.find(astr,tmp2+1);
					}
					//getlength
					while(str[tmp3]=='a') {
						tmp3++;
					}
					pf("%d,%d\n",tmp1,tmp3-1);
					break;
				}
			}
			if(flag==0)
				pf("0,0\n");
		}
	}
	return 0;
}