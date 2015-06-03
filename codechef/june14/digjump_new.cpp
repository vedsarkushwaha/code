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
	int len=str.length(),i;
	int hash[100010];
	for(i=0;i<len;i++) {
		if(arr[str[i]-'0']==-1) {
			if(i==0)
				arr[str[i]-'0']=0;
			else {
				arr[str[i]-'0']=hash[i-1]+1;
			}
			hash[i]=arr[str[i]-'0'];
		}
		else {
			hash[i]=mini(hash[i-1]+1,arr[str[i]-'0']+1);
			if(hash[i]<arr[str[i]-'0'])
				arr[str[i]-'0']=hash[i];
		}
	}
	printf("%d\n	",hash[len-1]);
	//cout<<str<<endl;
	//print(hash,str.length());
	return 0;
}
