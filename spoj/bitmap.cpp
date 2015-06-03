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
#define var(x) x i=0,j=0,k=0,l,tmp1,tmp2,tmp3,tmp=0,T
#define INT_MAX 10000
using namespace std;
int abs(int x) {
	if(x<0)
		return -x;
	else
		return x;
}
int main() {
	var(int);
	int n,m;
	int inp[200][200],opt[200][200];
	char ch;
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&n,&m);
		fr(i,0,200) {
			fr(j,0,200) {
				inp[i][j]=0;
				opt[i][j]=INT_MAX;
			}
		}
		sc("%c",&ch);
		fr(i,10,n+10) {
			fr(j,10,m+10) {
				sc("%c",&ch);
				inp[i][j]=ch-'0';
			}
			sc("%c",&ch);
		}
		//inp
		/*fr(i,0,n) {
			fr(j,0,m) {
				pf("%d ",inp[i][j]);
			}
			pf("\n");
		}
		pf("\n");*/
		
		fr(i,10,n+10) {
			fr(j,10,m+10) {
				if(inp[i][j]==1) {
					opt[i][j]=0;
					opt[i+1][j]=min(opt[i+1][j],1);
					opt[i][j+1]=min(opt[i][j+1],1);
					opt[i+1][j+1]=min(opt[i+1][j+1],2);
				}
				else {
					opt[i+1][j]=min(opt[i+1][j],opt[i][j]+1);
					opt[i][j+1]=min(opt[i][j+1],opt[i][j]+1);
					opt[i+1][j+1]=min(opt[i+1][j+1],opt[i][j]+2);
				}
			}
		}
		/*fr(i,10,10+n) {
			fr(j,10,10+m) {
				pf("%d ",opt[i][j]);
			}
			pf("\n");
		}*/
		//pf("\n");
		ifr(i,n+9,9) {
			ifr(j,m+9,9) {
				if(inp[i][j]==1) {
					opt[i][j]=0;
					opt[i-1][j]=min(opt[i-1][j],1);
					opt[i][j-1]=min(opt[i][j-1],1);
					opt[i-1][j-1]=min(opt[i-1][j-1],2);
				}
				else {
					opt[i-1][j]=min(opt[i-1][j],opt[i][j]+1);
					opt[i][j-1]=min(opt[i][j-1],opt[i][j]+1);
					opt[i-1][j-1]=min(opt[i-1][j-1],opt[i][j]+2);
				}
			}
		}
		fr(i,10,n+10) {
			fr(j,10,m+10) {
				pf("%d ",opt[i][j]);
			}
			pf("\n");
		}
	}
	return 0;
}
