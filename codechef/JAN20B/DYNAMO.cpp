#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int T;
	int res;
	long long N,A,B,C,D,E,S;
	long long temp;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&N);
		scanf("%lld",&A);
		temp = pow(10,N);
		S = temp * 2 + A;
		printf("%lld\n",S);
		fflush(stdout);
		scanf("%lld",&B);
		C = temp - B;
		printf("%lld\n",C);
		fflush(stdout);
		scanf("%lld",&D);
		E = temp - D;
		printf("%lld\n",E);
		fflush(stdout);
		scanf("%d",&res);
		if(res==-1) return 0;
	}
	return 0;
}