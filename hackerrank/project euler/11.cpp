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
#define f(i,m,n) for(i=m;i<n;i++)
#define ull unsigned long long
#define sc scanf
#define pf printf
#define var int i,j,k=0,tmp1,tmp2,tmp3,tmp
using namespace std;

void init(ull *a,int len) {
	int i;
	f(i,0,len)
		a[i]=0;
}
void print(ull *a,int len) {
	int i;
	f(i,0,len)
		printf("%llu",a[i]);
}

int main() {
	int a[28][28];
	var;
	f(i,0,28) {
		f(j,0,28) {
			if((i<4)||(j<4)||(i>23)||(j>23)) {
				a[i][j]=0;
			}
			else {
				sc("%d",&a[i][j]);
			}
		}
	}
	//print
	f(i,0,28) {
		f(j,0,28) {
			//pf("%d ",a[i][j]);
		}
		//pf("\n");
	}
	
	//calculation
	f(i,0,28) {
		f(j,0,28) {
			if((i<4)||(j<4)||(i>23)||(j>23)) {
				continue;
			}
			else {
				//up
				tmp=a[i][j]*a[i-1][j]*a[i-2][j]*a[i-3][j];
				if(k<tmp) {
					//pf("ba %d%d\n",i,j);
					k=tmp;
				}
				tmp=a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
				if(k<tmp) {
					//pf("fw %d%d\n",i,j);
					k=tmp;
				}
				tmp=a[i][j]*a[i][j-1]*a[i][j-2]*a[i][j-3];
				if(k<tmp) {
					//pf("up %d%d\n",i,j);
					k=tmp;
				}
				tmp=a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
				if(k<tmp) {
					//pf("dn %d%d\n",i,j);
					k=tmp;
				}
				tmp=a[i][j]*a[i-1][j-1]*a[i-2][j-2]*a[i-3][j-3];
				if(k<tmp) {
					//pf("dlu %d%d\n",i,j);
					k=tmp;
				}
				tmp=a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
				if(k<tmp) {
					//pf("drd %d%d\n",i,j);
					k=tmp;
				}
				tmp=a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
				if(k<tmp) {
					//pf("dld %d%d\n",i,j);
					k=tmp;
				}
				tmp=a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
				if(k<tmp) {
					//pf("dru %d%d\n",i,j);
					k=tmp;
				}
			}
		}
	}
	pf("%d",k);
	return 0;
}