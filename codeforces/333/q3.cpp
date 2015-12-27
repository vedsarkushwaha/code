#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int rail[402][402]={0};
int vis[402];

int findSP(int n,int tb) {
	var(int);
	// pf("%d %d\n\n",n,tb);
	queue<pair<int,int> > Q;
	Q.push(make_pair(1,0));
	pair<int,int> pr;
	vis[1]=1;
	while(!Q.empty()) {
		pr=Q.front();
		// pf("Current Node=%d\n",pr.first);
		Q.pop();
		// stk.pop();
		// pf("tmp=%d n=%d\n",tmp,n);
		if(pr.first==n) {
			return pr.second;
		}
		fr(j,1,n+1) {
			if(rail[pr.first][j]==tb && vis[j]==0) {
				// pf("%d-%d\n",pr.first,j);
				Q.push(make_pair(j,pr.second+1));
				vis[j]=1;
			} 
		}
	}
	return -1;
}

int main() {
	var(int);
	int n,m;
	sc("%d %d",&n,&m);
	fr(i,0,m) {
		sc("%d %d",&tmp1,&tmp2);
		rail[tmp1][tmp2]=1;
		rail[tmp2][tmp1]=1;
	}
	// fr(i,0,10) {
	// 	fr(j,0,10) {
	// 		pf("%d ",rail[i][j]);
	// 	}
	// 	pf("\n");
	// }
	// pf("\n");
	if(rail[1][n]) {
		pf("%d",findSP(n,0));
	}
	else {
		pf("%d",findSP(n,1));		
	}
	return 0;
}