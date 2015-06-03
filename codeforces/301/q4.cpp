#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	int r,s,p,i,j,k;
	sc("%d %d %d",&r,&s,&p);
	double dp[r+1][s+1][p+1],total,rtotal=0,stotal=0,ptotal=0;
	fr(i,0,r+1) fr(j,0,s+1) fr(k,0,p+1) dp[i][j][k]=0;
	dp[r][s][p]=1.0;
	ifr(i,r,-1) {
		ifr(j,s,-1) {
			ifr(k,p,-1) {
				total=(double)(i*j+j*k+k*i);
				// pf("%lf ",total);
				if(i!=0 && total!=0) {
					dp[i-1][j][k]+=(dp[i][j][k]*(k*i))/total;
				}
				if(j!=0 && total!=0) {
					dp[i][j-1][k]+=(dp[i][j][k]*(j*i))/total;
				}
				if(k!=0 && total!=0) {
					dp[i][j][k-1]+=(dp[i][j][k]*(k*j))/total;
				}
			}
		}
	}
	// pf("\n\n");
	// fr(i,0,r+1) {
	// 	fr(j,0,s+1) {
	// 		fr(k,0,p+1) {
	// 			pf("%lf ",(double)dp[i][j][k]);
	// 		}
	// 		pf("\n");
	// 	}
	// 	pf("\n");
	// }
	ifr(i,r,0) {
		rtotal+=dp[i][0][0];
		// pf("%lf %lf\n",rtotal,dp[i][0][0]);
	}
	ifr(i,s,0) {
		stotal+=dp[0][i][0];
		// pf("%lf %lf\n",stotal,dp[0][i][0]);
	}
	ifr(i,p,0) {
		ptotal+=dp[0][0][i];
		// pf("%lf %lf\n",ptotal,dp[0][0][i]);
	}
	pf("%.9lf %.9lf %.9lf",rtotal,stotal,ptotal);
	return 0;
}