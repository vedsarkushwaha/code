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
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
void print(char *str,int n) {
	var(int);
	fr(i,1,n+1)
		pf("%c",str[i]);
}
int main() {
	var(unsigned ll);
	unsigned ll r,iter,n,st;
	unsigned ll xx=1;
	sc("%llu %llu %llu %llu",&r,&iter,&n,&st);
	char state[66],statenew[66];
	state[0]=' ';
	state[n+1]=' ';
	xx=1;
	fr(i,1,n+1) {
		//pf("%llu %llu\n",xx,st&xx);
		if((st&xx)==xx) {
			state[n-i+1]='*';
			//pf("er");
		}
		else
			state[n-i+1]=' '; //replace this with ' '
		xx=xx<<1;
	}
	strcpy(statenew,state);
	fr(i,1,iter+1) {
		//pf("\n-%s-\n",statenew);
		if(i<10)
			pf("%llu   -",i);
		else if(i<100)
			pf("%llu  -",i);
		else if(i<1000)
			pf("%llu -",i);
		print(state,n);
		pf("-\n");
		fr(j,1,n+1) {
			tmp=0;
			if(state[j-1]=='*')
				tmp=(tmp|(1<<2));
			//printf("%llu ",tmp);
			if(state[j]=='*')
				tmp=(tmp|(1<<1));
			//printf("%llu ",tmp);
			if(state[j+1]=='*')
				tmp=(tmp|(1<<0));
			//printf("%llu\n",tmp);
			tmp3=r;
			while(tmp--) {tmp3=tmp3>>1;}
			if((tmp3&1)==1)
				statenew[j]='*';
			else
				statenew[j]=' ';
			//printf("%llu ",tmp3);
		}
		//change state
		if(strcmp(state,statenew)==0)
			break;
		strcpy(state,statenew);
		//pf("%s\n",state);
	}
	return 0;
}
