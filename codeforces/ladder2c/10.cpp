// #include<bits/stdc++.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <cassert>
#include <climits>
#include <algorithm>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
using namespace std;

int getmid(int N) {
	if(N%2) {
		return N/2+2;
	}
	else {
		return N/2+1;
	}
}

int getrev(int N, int C, int mid) {
	if(N%2) {
		// pf("enter:%d %d",mid,C);
		return (mid-2) - (C-mid);
	}
	else {
		return (mid-1) - (C-mid);
	}
}

int main() {
	var(int);
	int N,C;
	sc("%d %d",&N,&C);
	string str,str1;
	cin>>str;
	str1="-"+str;
	tmp=getmid(N);
	if(C>=tmp) {
		C = getrev(N, C,tmp);
		assert(C>0);
	}
	// pf("%d ",C);
	tmp--;
	if(N%2) tmp--;
	tmp5=0;
	int low=INT_MAX,high=INT_MIN;
	fr(i,1,tmp+1) {
		if(str1[i]!=str1[N-i+1]) {
			// pf("enter\n");
			low=min(low,i);
			tmp5+=min(abs(str1[i]-str1[N-i+1]),(26-abs(str1[i]-str1[N-i+1])));
			high=max(high,i);
		}
	}
	// pf("%d %d\n",low,INT_MAX);
	// pf("%d %d %d\n",low,high,tmp5);
	if(low==INT_MAX) pf("0");
	else {
		// pf("enter1\n");
		tmp5+=(high-low);
		pf("%d",tmp5+min(abs(high-C),abs(C-low)));
	}
	return 0;
}