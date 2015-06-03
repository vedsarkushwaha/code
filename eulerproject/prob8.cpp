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
#define f(i,m,n) for(i=m;i<n;i++)
#define ull unsigned long long
#define sc scanf
#define pf printf
using namespace std;

void init(ull *a,int len) {
	int i;
	f(i,0,len)
		a[i]=0;
}
void print(string a,int len) {
	int i;
	f(i,0,len)
		printf("%d",a[i]-'0');
}

int main() {
	string str;
	ull i,sum,T,len,max,N,K,j;
	sc("%llu",&T);
	while(T--) {
		cin>>K>>N;
		//cout<<str<<" "<<N<<endl;
		cin>>str;
		len=str.length();
		//sc("%llu",&N);
		sum=1;
		f(i,0,N)
			sum*=(str[i]-'0');
		max=sum;
		f(i,N,len) {
			if(str[i-N]=='0') {
				sum=1;
				f(j,i-(N-1),i) {
					sum*=(str[j]-'0');
				}
			}
			else {
				sum/=(str[i-N]-'0');
			}
			sum*=(str[i]-'0');
			if(sum>max)
				max=sum;
		}
		pf("%llu\n",max);
	}
	return 0;
}
