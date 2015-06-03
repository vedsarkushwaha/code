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
#include<utility>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
#define md 1000000007
using namespace std;
struct mat {
	unsigned ll arr[15][15];
};
mat operator*(mat a,mat b) {
	mat c;
	int i,j,k;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++) {
			c.arr[i][j]=0;
			for(k=0;k<15;k++)
				c.arr[i][j]=(c.arr[i][j]+(a.arr[i][k]*b.arr[k][j])) % md;
			c.arr[i][j]=c.arr[i][j] % md;
		}
	return c;
}
void print(mat m) {
	var(int);
	fr(i,0,15) {
		fr(j,0,15) {
			pf("%llu ",m.arr[i][j]);
		}
		pf("\n");
	}
}

mat power(mat x,unsigned long long y) {
	mat temp;
	mat iden;
	var(unsigned ll);
	fr(i,0,15) {
		fr(j,0,15) {
			if(i==j)
				iden.arr[i][j]=1;
			else
				iden.arr[i][j]=0;
		}
	}
	if(y==0)
		return iden;
	temp=power(x, y/2);
	//pf("\ntemp\n");
	//print(temp);
	//pf("\ntemp\n");
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
int main() {
	unsigned ll N,K;
	unsigned ll arr[116];
	int brick[16];
	var(unsigned ll);
	mat base,cal_mat;
	fr(i,0,16)
		brick[i]=0;
	fr(i,0,116)
		arr[i]=0;
	sc("%llu",&N);
	sc("%llu",&K);
	fr(i,0,K) {
		sc("%llu",&tmp);
		brick[tmp]+=1;
	}
	fr(i,101,116) {
		fr(j,1,16) {
			arr[i]+=(arr[i-j]*brick[j]);
		}
		arr[i]+=brick[i-100];
	}
	//fr(i,0,15)
		//pf("%llu ",arr[101+i]);
	//pf("\n");
	if(N<=15)
		pf("%llu",arr[100+N]*2);
	else {
		//initialize base matrix
		fr(i,0,15) {
			fr(j,0,15) {
				if(i==0) {
					base.arr[i][j]=brick[(j+1)]; //defined by bricks
				}
				else {
					if(i==j+1)
						base.arr[i][j]=1;
					else
						base.arr[i][j]=0;
				}
			}
		}
		cal_mat=power(base,N-15);
		fr(i,0,15)
			tmp1+=cal_mat.arr[0][i]*arr[14+101-i];
		tmp1=(tmp1*2) % md;
		pf("%llu",tmp1);
	}
	//print(base);
	//pf("\n");
	//print(cal_mat);
	//print(base*base);
	return 0;
}
