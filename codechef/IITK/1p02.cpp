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
	string str;
	cin>>str;
	int len=str.length();
	int mx=1,cnt=1;
	char ch=str[0],c;
	c=ch;
	for(int i=1;i<len;i++) {
		if(str[i]==ch) {
			cnt++;
		}
		else {
			if(mx<cnt) {
				mx=cnt;
				c=ch;
			}
			else if((mx==cnt)&&(c>ch)) {
				mx=cnt;
				c=ch;
			}
			ch=str[i];
			cnt=1;
		}
	}
	//pf("%c %c %d %d\n",c,ch,cnt,mx);
	//if(c>ch)
		//pf("g");
	if(mx<cnt) {
		//pf("2");
		mx=cnt;
		c=ch;
	}
	else if((mx==cnt)&&(c>ch)) {
		mx=cnt;
		//pf("1");
		c=ch;
	}
	pf("%c\n%d",c,mx);
	return 0;
}
