#include<cstdio>
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
using namespace std;

int main() {
	var(ll);
	sc("%lld",&T);
	while(T--) {
		sc("%lld",&tmp);
		tmp1=(tmp*tmp*tmp+3*tmp*tmp+2*tmp)/6;
		tmp3=tmp;
		tmp=tmp/2;
		if(tmp3%2==0)
			tmp2=(tmp*(tmp+1)*(2*tmp+1))/3-(tmp*(tmp+1))/2;
		else
			tmp2=(tmp*(tmp+1)*(2*tmp+1))/3+(tmp*(tmp+1))/2;
		pf("%lld\n",tmp1+tmp2);
	}
	return 0;
}
