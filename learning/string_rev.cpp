#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
void rev(char *str,int i,int j) {
	char ch;
	while(i<=j) {
		//swap(str[i],str[j])
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
		i++;j--;
	}
}
void fun(char *str,int len) {
	int i=-1,j=0;
	do {
		i=i+1;
		if((str[i]==' ')||(i==len)) {
			//reverse j to i-1
			rev(str,j,i-1);
			j=i+1;
		}
	}while(i<len);
	rev(str,0,i-1);
}
int main() {
	char str[100]="northern california usa";
	fun(str,23);
	printf("%s",str);
	return 0;
}
