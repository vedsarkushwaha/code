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
	int n,m;
	string st1,st2;
	sc("%d %d",&n,&m);
	map<string,string> mp;
	fr(i,0,m) {
		cin>>st1>>st2;
		mp.insert(make_pair(st1,st2));
	}
	fr(i,0,n) {
		cin>>st1;
		st2=(mp.find(st1))->second;
		if(st2.length()<st1.length())
			cout<<st2<<' ';
		else
			cout<<st1<<' ';
	}
	return 0;
}
