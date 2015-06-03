#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int cnt_two(unsigned long long x) {
	int cnt=0;
	while(x%2==0) {
		x=x/2;
		cnt++;
	}
	return cnt;
}
int main() {
	int n,c;
	unsigned long long q,ans1,ans2;
	scanf("%d",&n);
	while(n--) {
		scanf("%llu",&q);
		c=cnt_two(q);
		ans1=(1<<c)-1;
		printf("%llu %llu\n",q-ans1,q+ans1);
	}
	return 0;
}
