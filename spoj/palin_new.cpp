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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
using namespace std;
unsigned ll power(unsigned ll x,unsigned ll y) {
	unsigned ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
unsigned ll gcd(unsigned ll a, unsigned ll b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}
string palin(string str) {
	var(int);
	int len=str.length();
	string newstr,tmpstr;
	fr(i,0,len/2) {
		newstr+=str[i];
	}
	tmpstr=newstr;
	reverse(newstr.begin(),newstr.end());
	if(len%2==0)
		return tmpstr+newstr;
	else
		return tmpstr+str[len/2]+newstr;
}
int main() {
	var(int);
	string str;
	sc("%d",&T);
	while(T--) {
		cin>>str;
		cout<<palin(str)<<endl;
	}
	return 0;
}
