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
int getlength(char *a) {
	var(int);
	i=0;
	while(a[i]!='\0') {
		i++;
	}
	return i;
}
bool chk_permut(char *a,char *b) {
	map<char,int> mp;
	map<char,int>::iterator itt;
	pair<map<char,int>::iterator,bool> it;
	var(int);
	int len=getlength(a);
	pf("%d",len);
	fr(i,0,len) {
		it=mp.insert(make_pair(a[i],1));
		if(it.second==false)
			(it.first->second)+=1;
	}
	for(itt=mp.begin();itt!=mp.end();++itt) {
		pf("%c %d",itt->first,itt->second);
	}
	return 1;
}
int main() {
	char a[30],b[30];
	sc("%s %s",a,b);
	if(chk_permut(a,b))
		pf("Yes\n");
	else
		pf("No\n");
	return 0;
}
