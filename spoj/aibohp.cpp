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
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
int d[6101][6101];
int main() {
	string str1,str2;
	var(int);int T;
	sc("%d",&T);
	while(T--) {
		cin>>str1;
		str2=str1;
		reverse(str2.begin(),str2.end());
		//cout<<str1<<' '<<str2<<endl;
		fr(i,0,str2.length()+1)
			d[0][i]=i;
		fr(i,0,str1.length()+1)
			d[i][0]=i;
		fr(i,1,str1.length()+1) {
			fr(j,1,str2.length()+1) {
				if(str1[i-1]==str2[j-1]) {
					d[i][j]=d[i-1][j-1];
				}
				else {
					d[i][j]=min(min(d[i-1][j],d[i][j-1])+1,d[i-1][j-1]+2);
				}
			}
		}
		pf("%d\n",d[str1.length()][str2.length()]/2);
	}
	return 0;
}