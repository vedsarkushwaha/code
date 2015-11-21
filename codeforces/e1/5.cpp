#include<bits/stdc++.h>
using namespace std;

int d[35][35][55],n,m,k;

int f(int r,int c,int to) {
	if(d[r][c][to]!=-1) return d[r][c][to];
	else if(r*c==to||to==0) return d[r][c][to]=0;
	else if(r*c<to) return d[r][c][to]=1e7;
	d[r][c][to]=1e8;
	for(int i=1;i<r;i++){
	    for(int j=0;j<=to;j++) d[r][c][to]=min(d[r][c][to],f(i,c,j)+f(r-i,c,to-j)+c*c);
	}
	for(int i=1;i<c;i++){
	    for(int j=0;j<=to;j++) d[r][c][to]=min(d[r][c][to],f(r,i,j)+f(r,c-i,to-j)+r*r);
	}
	return d[r][c][to];
}

int main() {
	memset(d,-1,sizeof(d));
	int T;
	cin>>T;
	while(T--) {
	    cin>>n>>m>>k;
	    cout<<f(n,m,k)<<endl;
	}
	return 0;
}