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

string incr(string str) {
	var(int);
	tmp=str.length();
	ifr(i,tmp-1,-1) {
		//pf(" c=%c ",str[i]);
		if(str[i]!='9') {
			str[i]=str[i]+1;
			//pf(" 1 ");
			return str;
		}
		else {
			str[i]='0';
		}
	}
}

string even(string inp) {
	var(int);
	string lft,rgt;
	int len=inp.length();
	ifr(i,len/2-1,-1) {
		rgt+=inp[i];
	}
	fr(i,0,len/2) {
		lft+=inp[i];
	}
	//comp lft rgt
	i=0;
	while((i<len/2)&&(inp[i+len/2]==rgt[i])) {
		i++;
	}
	if(inp[i+len/2]<rgt[i])
		return lft+rgt;
	//cout<<lft<<endl;
	lft=incr(lft);
	//cout<<lft<<endl;
	rgt=lft;
	reverse(rgt.begin(),rgt.end());
	return lft+rgt;
}

string odd(string inp) {
	var(int);
	string lft,rgt;
	int len=inp.length();
	ifr(i,len/2-1,-1) {
		rgt+=inp[i];
	}
	fr(i,0,len/2+1) {
		lft+=inp[i];
	}
	//comp lft rgt
	i=0;
	while((i<len/2)&&(inp[i+len/2+1]==rgt[i])) {
		i++;
	}
	if(inp[i+len/2+1]<rgt[i])
		return lft+rgt;
	//cout<<lft<<endl;
	lft=incr(lft);
	//cout<<lft<<endl;
	rgt="";
	fr(i,0,lft.length()-1)
		rgt+=lft[i];
	reverse(rgt.begin(),rgt.end());
	return lft+rgt;
}

string get_palin(string inp) {
	string lft,rgt;
	int len;var(int);
	//chk 999
	tmp3=0;
	fr(i,0,inp.length()) {
		if(inp[i]!='9') {
			tmp3=1;
			break;
		}
	}
	if(tmp3==0) {
		lft='1';
		fr(i,0,inp.length()) {
			lft+='0';
		}
		lft[lft.length()-1]='1';
		return lft;
	}
	len=inp.length();
	if(len%2==0) {
		//even
		return even(inp);
	}
	else {
		//pf("Dance");
		return odd(inp);
		//odd
	}
	
}

int main() {
	var(int);
	string str;
	int T;
	sc("%d",&T);
	while(T--) {
		cin>>str;
		cout<<get_palin(str)<<endl;
	}
	return 0;
}
