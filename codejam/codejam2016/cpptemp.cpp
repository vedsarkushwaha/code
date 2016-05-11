#include <cstdio>
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

struct node {
	int R,G,B;
};

int main() {
	int R,C,r,c,N;
	var(int);
	sc("%d %d %d",&r,&c,&N);
	sc("%d %d",&R,&C);
	node mat[N][N];
	fr(i,0,N) {
		fr(j,0,N) {
			if(i%N==0 && j%N==0) {
				sc("%d %d %d",&tmp1,&tmp2,&tmp3);
				mat[i][j].R=tmp1;
				mat[i][j].G=tmp2;
				mat[i][j].B=tmp3;
			}
		}
	}
	float avgR,avgG,avgB;
	fr(i,0,N) {
		fr(j,0,N) {
			if(i%N==0 && j%N==0) {
				if(i+N>=R || j+N>=C) {
					avgR = mat[i][j].R;
					avgG = mat[i][j].G;
					avgB = mat[i][j].B;
				}
				else {
					avgR = (mat[i][j].R + mat[i+N][j+N].R)/(N+1);
					avgG = (mat[i][j].G + mat[i+N][j+N].G)/(N+1);
					avgB = (mat[i][j].B + mat[i+N][j+N].B)/(N+1);
				}
			}
			else {
				mat[i][j].R = avgR;
				mat[i][j].G = avgG;
				mat[i][j].B = avgB;
			}
		}
	}
	return 0;
}