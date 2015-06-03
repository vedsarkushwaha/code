#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long gen_ns(int i) {
	unsigned long long x=1;
	int j;
	for(j=1;j<i;j++) {
		x*=10;
		x+=1;
	}
	x*=9;
	return x;
}	
int main() {
	unsigned long long x=10000;
	long double y;
	cin>>y;
	//y=1/77;
	//y*=100000;
	printf("%.20Lf\n",x/y);
	return 0;
}
