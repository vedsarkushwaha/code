#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	int flag=0,i;
	long long num=21;
	do {
		if(num%16!=0) {
			//cout<<"Not "<<num<<endl;
			flag=1;
		}
		if(num%9!=0) {
			//cout<<"Not "<<num<<endl;
			flag=1;
		}
		else if(num%5!=0) {
			//cout<<"Not "<<num<<endl;
			flag=1;
		}
		else if(num%7!=0) {
				//cout<<"Not "<<num<<endl;
				flag=1;
		}
		else if(num%11!=0) {
				//cout<<"Not "<<num<<endl;
				flag=1;
		}
		else if(num%13!=0) {
				//cout<<"Not "<<num<<endl;
				flag=1;
		}
		else if(num%17!=0) {
				//cout<<"Not "<<num<<endl;
				flag=1;
		}
		else if(num%19!=0) {
				//cout<<"Not "<<num<<endl;
				flag=1;
		}
		if(flag==0) {
			cout<<num<<endl;
			exit(0);
		}
		flag=0;
		num++;
	}while(1);
	return 0;
}
