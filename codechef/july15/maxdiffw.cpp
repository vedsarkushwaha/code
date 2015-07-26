#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
int N;
int mat[50][50];
bool dMoves[50][50];

bool chkend(int v) {
	var(int);
	fr(i,0,N) {
		// pf("%d %d\n",v,i);
		if(v==i) continue;
		if(dMoves[v][i]==0) return 1;
	}
	return 0;
}
int main() {
	var(int);
	sc("%d",&N);
	int chefS=-1;
	int maxi=0,maxj=0;
	fr(i,0,N) {
		fr(j,0,N) {
			sc("%d",&mat[i][j]);
			if(i==0 && mat[maxi][maxj]<mat[i][j]) maxi=i,maxj=j;
		}
	}
	ll myScore=0, chScore=0;
	pf("%d %d\n",maxi+1,maxj+1);
	bool move=0;
	dMoves[maxi][maxj]=1;
	myScore=mat[maxi][maxj];
	while(1) {
		fflush(stdout);
		if(move==0) {
			if(!chkend(maxj)) {
				pf("%lld %lld\n",myScore,chScore);
				assert(myScore>=chScore);
				return 0;
			}
			sc("%d %d",&i,&j);
			i-=1,j-=1;
			dMoves[i][j]=1;
			chScore+=mat[i][j];
			move=1;
		}
		else if(move==1) {
			maxi=j,maxj=0;
			if(!chkend(maxi)) {
				pf("%lld %lld\n",myScore,chScore);
				assert(myScore>=chScore);
				return 0;
			}
			fr(k,0,N) if(mat[maxi][maxj]<mat[maxi][k] && dMoves[maxi][k]==0) maxj=k;
			pf("%d %d\n",maxi+1,maxj+1);
			dMoves[maxi][maxj]=1;
			myScore+=mat[maxi][maxj];
			move=0;
		}
	}
	return 0;
}