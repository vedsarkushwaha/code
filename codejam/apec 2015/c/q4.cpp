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
char arr[100][100];
void init();
int fill(int,int,int,int);
int get_empty_row(int);
int chk_fill();
int get_empty_row(int col1,int col2,int col3,int col4) {
	var(int);
	fr(i,0,100) {
		if(arr[][]=='x')
	}
}
void init() {
	var(int);
	fr(i,0,100)
		fr(j,0,100)
			arr[i][j]='.';
}
int fill(int t,int r,int x,int H) {
	tmp=get_empty_row(x);
	if(t==1) {
		if((r==0)||(r==2)) {
			if(tmp+2>=H)
				return -1;
			arr[tmp][x+1]='x';arr[tmp+1][x+1]='x';
			arr[tmp+1][x]='x';arr[tmp+2][x]='x';
		}
		else if((r==1)||(r==3)) {
			if(tmp+1>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp][x+1]='x';
			arr[tmp+1][x+1]='x';arr[tmp+1][x+2]='x';
		}
	}
	else if(t==2) {
		if((r==0)||(r==2)) {
			if(tmp+2>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp+1][x+1]='x';
			arr[tmp+1][x]='x';arr[tmp+2][x+1]='x';
		}
		else if((r==1)||(r==3)) {
			if(tmp+1>=H)
				return -1;
			arr[tmp][x+1]='x';arr[tmp][x+2]='x';
			arr[tmp+1][x]='x';arr[tmp+1][x+1]='x';
		}
	}
	else if(t==3) {
		if((r==0) {
			if(tmp+2>=H)
				return -1;
			arr[tmp][x+1]='x';arr[tmp][x]='x';
			arr[tmp+1][x]='x';arr[tmp+2][x]='x';
		}
		else if(r==1) {
			if(tmp+1>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp][x+1]='x';
			arr[tmp][x+2]='x';arr[tmp+1][x+2]='x';
		}
		else if(r==2) {
			if(tmp+2>=H)
				return -1;
			arr[tmp][x+1]='x';arr[tmp+1][x+1]='x';
			arr[tmp+2][x+1]='x';arr[tmp+2][x]='x';
		}
		else if(r==3) {
			if(tmp+1>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp+1][x]='x';
			arr[tmp+1][x+1]='x';arr[tmp+1][x+2]='x';
		}
	}
	else if(t==4) {
		if((r==0) {
			if(tmp+2>=H)
				return -1;
			arr[tmp][x+1]='x';arr[tmp][x]='x';
			arr[tmp+1][x+1]='x';arr[tmp+2][x+1]='x';
		}
		else if(r==1) {
			if(tmp+1>=H)
				return -1;
			arr[tmp+1][x]='x';arr[tmp+1][x+1]='x';
			arr[tmp+1][x+2]='x';arr[tmp][x+2]='x';
		}
		else if(r==2) {
			if(tmp+2>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp+1][x]='x';
			arr[tmp+2][x]='x';arr[tmp+2][x+1]='x';
		}
		else if(r==3) {
			if(tmp+1>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp+1][x]='x';
			arr[tmp][x+1]='x';arr[tmp][x+2]='x';
		}
	}
	else if(t==5) {
		if(tmp+1>=H)
			return -1;
		arr[tmp][x]='x';arr[tmp+1][x]='x';
		arr[tmp][x+1]='x';arr[tmp+1][x+1]='x';
	}
	else if(t==6) {
		if((r==0)||(r==2)) {
			if(tmp+3>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp+1][x]='x';
			arr[tmp+2][x]='x';arr[tmp+3][x]='x';
		}
		else if((r==1)||(r==3)) {
			arr[tmp][x]='x';arr[tmp][x+1]='x';
			arr[tmp][x+2]='x';arr[tmp][x+3]='x';
		}
	}
	else if(t==7) {
		if(r==0) {
			if(tmp+1>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp+1][x+1]='x';
			arr[tmp][x+1]='x';arr[tmp][x+2]='x';
		}
		else if(r==1) {
			if(tmp+2>=H)
				return -1;
			arr[tmp+1][x]='x';arr[tmp+1][x+1]='x';
	s		arr[tmp][x+1]='x';arr[tmp+2][x+1]='x';
		}
		else if(r==2) {
			if(tmp+1>=H)
				return -1;
			arr[tmp][x+1]='x';arr[tmp+1][x+1]='x';
			arr[tmp+1][x]='x';arr[tmp+1][x+2]='x';
		}
		else if(r==3) {
			if(tmp+1>=H)
				return -1;
			arr[tmp][x]='x';arr[tmp+1][x+1]='x';
			arr[tmp+1][x]='x';arr[tmp+2][x+2]='x';
		}
	}
}
int main() {
	var(int);
	int T,N,W,H,r,x,t;
	
	return 0;
}
