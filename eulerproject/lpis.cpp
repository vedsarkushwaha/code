#include<iostream>
#include<cmath>
using namespace std;
int arr[2000000]={2,3,5,7,11,13,17,19};
int len;
int chk_prime(int x) {
	int i,temp;
	if(((x-1)%6==0)||((x+1)%6==0)) {
		temp=pow(x,.5);
		for(i=0;(i<len)&&(arr[i]<=temp);i++) {
			if(x%arr[i]==0)
				return 0;
		}
	}
	else
		return 0; 
	return 1;
}
int next_prime(int x) {
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
	int a=19,b=20000000;
	long long sum=77;
	len=8;
	do {
		arr[len]=next_prime(arr[len-1]);
		cout<<arr[len]<<" ";
		sum+=arr[len];
		len++;
	}while(arr[len-1]<=b);
	//cout<<sum;
	cout<<sum-arr[len-1];
	return 0;
}
