#include <cstdio>
#include <vector>
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
int mat[62][62];
void print(int N) {
	var(int);
	fr(i,1,N+1) {
		fr(j,1,N+1) {
			pf("%d ",mat[i][j]);
		}
		pf("\n");
	}
}

int main() {
	var(int);
	int T,N;
	sc("%d",&T);
	while(T--) {
		int N,K,currI=1,currJ=1;
		sc("%d %d",&N,&K);
		fr(i,1,N+1) {
			fr(j,1,N+1) {
				sc("%d",&tmp);
				mat[i][j]=0;
				if(tmp!=0) {
					mat[currI][currJ]=tmp;
					currJ++;
					if(currJ>N) {
						currJ=1;
						currI++;
					}
				}
			}
		}
		int IP[K+1];
		IP[0]=-1;
		fr(i,0,K) {
			sc("%d",&tmp);
			IP[i+1]=tmp;
		}
		print(N);
	}
	return 0;
}