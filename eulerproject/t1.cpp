#include<iostream>
using namespace std;
int chk_prime(long long x) {
	int i;
	for(i=2;i<=x/2;i++) {
		if(x%i==0)
			return 0;
	}
	return 1;
}
long long next_prime(long long x) {
	int i;
	if(x==1)
		return 2;
	if(x==2)
		return 3;
	while(1) {
		x=x+2;
		if(chk_prime(x))
			return x;
	}
}
int main() {
	long long max,temp=1;
	cin>>max;
	if(chk_prime(max))
		return max;
	while(temp<max) {
		temp=next_prime(temp);
		if(max%temp==0) {
			cout<<temp<<endl;
		}
	}
	return 0;
}
