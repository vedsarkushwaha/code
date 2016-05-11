#include <cstdio>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0

using namespace std;

int main() {
	var(int);
	int T,N;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		// if(N<7) {
			pf("-1\n");
			continue;
		// }
		pf("%d\n",3*(N-3) + 2 + (N-3));
		pf("1 2\n");
		pf("2 3\n");

		// long side printing
		fr(i,4,N) {
			pf("%d %d\n",i,i+1);
		}

		fr(i,1,4) {
			fr(j,4,N+1) {
				pf("%d %d\n",i,j);
			}
		}
		pf("1\n");
	}
	return 0;
}