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
	int N;
	int arr[6];
	int i;
	fr(i,0,6)
		sc("%d",&arr[i]);
	//start the game
	int cnt=0;
	int two_chk=0;
	int thr_chk=0;
	fr(i,0,6) {
		if(arr[i]>1) {
			pf("Winning");
			break;
		}
		if(arr[i]==1) {
			cnt++;
			if(arr[(i+3)%6]==1)
				two_chk=1;
			if((arr[(i+2)%6]==1)&&(arr[(i+4)%6]==1))
				thr_chk=1;
		}	
	}
	if((cnt==0)||(cnt==6))
		pf("Losing");
	else if((cnt==1)||(cnt==4)||(cnt==5))
		pf("Winning");
	else if(cnt==2)
		if(two_chk==1)
			pf("Losing");
		else
			pf("Winning");
	else if(cnt==3)
		if(thr_chk==1)
			pf("Losing");
		else
			pf("Winning");
	return 0;
}
