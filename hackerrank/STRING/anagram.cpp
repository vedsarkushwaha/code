#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
#include<utility>
void init(int *arr) {
	for(int i=0;i<26;i++)
		arr[i]=0;
}
int mod(int x) {
	if(x<0)
		return -x;
	else
		return x;
}
using namespace std;
int main() {
	string str;
	int len,cnt,i,j,temp,T;
	int arr[26];
	scanf("%d",&T);
	while(T--) {
		cin>>str;
		cnt=0;
		len=str.length();
		if((len&1)==1) {
			printf("-1\n");
		}
		else {
			temp=len/2;
			init(arr);
			for(i=0;i<temp;i++) {
				arr[str[i]-'a']++;
			}
			for(i=temp;i<len;i++) {
				arr[str[i]-'a']--;
			}
			for(i=0;i<26;i++) {
				cnt+=mod(arr[i]);
			}
			printf("%d\n",cnt/2);
		}
	}
	return 0;
}
