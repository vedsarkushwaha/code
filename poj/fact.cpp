#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int T,n;
	unsigned long long sum;
	scanf("%d",&T);
	while(T--) {
		sum=0;
		scanf("%d",&n);
		while(n>=5) {
			n=n/5;
			sum+=n;
		}
		printf("%llu\n",sum);
	}
	return 0;
}	
