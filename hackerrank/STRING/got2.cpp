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

