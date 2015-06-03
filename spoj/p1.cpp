#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
unsigned long long get_sum(int n) {
	unsigned long long sum=0;
	int i;
	for(i=1;i<n;i++) {
		if(n%i==0)
			sum+=i;
	}
	return sum;
}
int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		printf("%Lu\n",get_sum(n));
	}
	return 0;
}
