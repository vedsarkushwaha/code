#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int arr[10];

void init() {
	int i;
	for(i=0;i<=9;i++)
		arr[i]=-1;
}

int mini(int a,int b) {
	if(a<b)
		return a;
	else
		return b;
}

void print(int *a,int len) {
	int i;
	for(i=0;i<len;i++)
		printf("%d",a[i]);
	printf("\n");
}

int main() {
	string str;
	cin>>str;
	init();
	int len=str.length();
	int hash[100010];
	while(len--) {
		if(arr[str[len]-'0']==-1) {
			if(len==str.length()-1)
				arr[str[len]-'0']=0;
			else {
				arr[str[len]-'0']=hash[len+1]+1;
			}
			hash[len]=arr[str[len]-'0'];
		}
		else {
			hash[len]=mini(hash[len+1]+1,arr[str[len]-'0']+1);
			if(hash[len]<arr[str[len]-'0'])
				arr[str[len]-'0']=hash[len];
		}
	}
	//printf("%d",hash[0]);
	cout<<str<<endl;
	print(hash,str.length());
	return 0;
}
