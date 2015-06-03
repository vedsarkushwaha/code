#include<cstdio>
#include<cmath>
#define sc scanf
#define pf printf
#define var(x) x tmp3,tmp
using namespace std;

void print(int num) {
	var(int);
	if(num==1) {
		pf("2(0)");
		return;
	}
	if(num==2) {
		pf("2");
		return;
	}
	if(num==3) {
		pf("2+2(0)");
		return;
	}
	tmp=log2(num);
	pf("2(");print(tmp);pf(")");
	if(num-pow(2,tmp)>0) {
		pf("+");
		print(num-pow(2,tmp));
	}
}

int main() {
	var(int);
	tmp3=7;
	while(tmp3--) {
		sc("%d",&tmp);
		pf("%d=",tmp);
		print(tmp);
		pf("\n");
	}
	return 0;
}
