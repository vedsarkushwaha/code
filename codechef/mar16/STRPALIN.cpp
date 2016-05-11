#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3
using namespace std;

bool chkPalindron(string a) {
	var(int);
	fr(i,0,a.length()/2) {
		if(a[i]!=a[a.length()-i-1]) return 0;
	}
	return 1;
}
bool debug=0;
int main() {
	var(int);
	string A,B,tmp;
	int T,flag;
	sc("%d",&T);
	while(T--) {
		cin>>A;
		cin>>B;
		flag=0;
		int arr[26]={0};
		fr(i,0,A.length()) {
			arr[A[i]-'a']++;
		}
		fr(i,0,B.length()) {
			if(arr[B[i]-'a']!=0) {
				flag=1;
				break;
			}
		}
		if(flag) pf("Yes\n");
		else pf("No\n");
	}
	return 0;
}