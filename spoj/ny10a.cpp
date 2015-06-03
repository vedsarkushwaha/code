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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
using namespace std;

int main() {
	var(int);
	int arr[8]={0};
	int N;
	string str,tmpstr;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		cin>>str;
		fr(i,0,8)
			arr[i]=0;
		fr(i,0,38) {
			if(str[i]=='H') {
				if(str[i+1]=='H') {
					if(str[i+2]=='H')
						arr[0]++;
					else
						arr[1]++;
				}
				else {
					if(str[i+2]=='H')
						arr[2]++;
					else
						arr[3]++;
				}
			}
			else {
				if(str[i+1]=='H') {
					if(str[i+2]=='H')
						arr[4]++;
					else
						arr[5]++;
				}
				else {
					if(str[i+2]=='H')
						arr[6]++;
					else
						arr[7]++;
				}
			}
		}
		pf("%d %d %d %d %d %d %d %d %d\n",N,arr[7],arr[6],arr[5],arr[4],arr[3],arr[2],arr[1],arr[0]);
	}
	return 0;
}
