#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int md=1000000007;

void printVec(vi vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d ",vec[i]);
	}
	pf("\n");
}

int main() {
	var(int);
	int T,M,N,s;
	sc("%d",&T);
	while(T--) {
		sc("%d %d %d",&N,&M,&s);
		int seqPow[M+1];
		fr(i,1,M+1) {
			sc("%d",&tmp);
			seqPow[i]=tmp;
		}
		ll arr[M+1][N+1];
		fr(i,0,M+1) {
			fr(j,0,N+1) {
				arr[i][j]=0;
			}
		}
		arr[0][s]=1;
		fr(i,1,M+1) {
			int jump=seqPow[i];
			fr(j,1,N+1) {
				if(arr[i-1][j]!=0) {
					if(j-jump>0) {
						arr[i][j-jump]+=arr[i-1][j];
						arr[i][j-jump]=arr[i][j-jump]%md;
					}
					if(j+jump<=N) {
						arr[i][j+jump]+=arr[i-1][j];
						arr[i][j+jump]=arr[i][j+jump]%md;
					}
					arr[i-1][j]=0;
				}
			}
		}
		fr(i,1,N+1) pf("%lld ",arr[M][i]);
		pf("\n");
	}
	return 0;
}