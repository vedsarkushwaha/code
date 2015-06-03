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
int mat[100][100];
int main() {
	var(int);
	int N,M,K;
	sc("%d %d %d",&N,&M,&K);
	while(K--) {
		sc("%d %d",&tmp1,&tmp2);
		mat[tmp1-1][tmp2-1]=1;
	}
	tmp=0;
	fr(i,0,N) {
		j=0;
		while(j<M) {
			if((mat[i][j]==0)&&(j<M)) {
				tmp++;
				//pf("%d %d 0\n",i+1,j+1);
				while((j<M)&&(mat[i][j]==0)) {j++;}
				while((j<M)&&(mat[i][j]==1)) {j++;}
			}
			else {j++;}
		}
	}
	pf("%d\n",tmp);
	fr(i,0,N) {
		j=0;
		while(j<M) {
			if((mat[i][j]==0)&&(j<M)) {
				tmp++;
				pf("%d %d 0\n",i+1,j+1);
				while((j<M)&&(mat[i][j]==0)) {j++;}
				while((j<M)&&(mat[i][j]==1)) {j++;}
			}
			else {j++;}
		}
	}
	return 0;
}
