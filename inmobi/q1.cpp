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
int mat[2000][2000];
int cnt=0;
int N;
void chk(string str,int i,int x,int y) {
	if((x>0)&&(y>0)) {
		//pf("%d %d\n",x,y);
		if(str.length()==i)
			cnt++;
		if(str[i]==mat[x-1][y-1]) {
			chk(str,i+1,x-1,y-1);
		}
		if(str[i]==mat[x-1][y+1]) {
			chk(str,i+1,x-1,y+1);
		}
		if(str[i]==mat[x+1][y-1]) {
			chk(str,i+1,x+1,y-1);
		}
		if(str[i]==mat[x+1][y+1]) {
			chk(str,i+1,x+1,y+1);
		}
	}
}
void fun(string str) {
	var(int);
	fr(i,3,N+3) {
		fr(j,3,N+3) {
			if(mat[i][j]==str[0]) {
				//pf("\n%d %d\n",i,j);
				chk(str,1,i,j);
			}
		}
	}
}
				
int main() {
	var(int);
	
	string str;
	sc("%d\n",&N);	
	fr(i,3,N+3) {
		fr(j,3,N+3) {
			if(N+2==j)
				sc("%c\n",&tmp);
			else
				sc("%c ",&tmp);
			mat[i][j]=tmp;
			//pf("%d ",tmp);
		}
	}
	/*fr(i,3,N+3) {
		fr(j,3,N+3) {
			pf("%c",arr[i][j]);
		}
		pf("\n");
	}*/
	cin>>str;
	fun(str);
	pf("%d",cnt);
	return 0;
}
