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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

int main() {
	var(ll);
	string str,str1,tmpstr;
	int T,num;
	sc("%d",&T);
	while(T--) {
		cin>>str;
		cin>>k;
		tmp=str.length();
		num=0;
		str1.clear();
		tmp3=0;
		fr(i,0,tmp) {
			if((str[i]>='0') and (str[i]<='9')) {
				while((str[i]>='0') and (str[i]<='9')) {
					num=(num*10)+(str[i]-'0');
					i++;
					if(i>=tmp)
						break;
				}
				i--;
				//copy string in str1 num times
				if(num==0)
					str1.clear();
				else {
					tmpstr=str1;
					while(--num) {
						if(str1.length()+tmpstr.length()>=k) {
							k-=str1.length();
							tmp3=1;
							cout<<str1[k-1]<<endl;
							break;
						}
						str1+=tmpstr;
					}
				}
			}
			else {
				str1+=str[i];
				if(str1.length()==k) {
					cout<<str1[k-1]<<endl;
					tmp3=1;
					break;
				}
			}
			if(tmp3==1)
				break;
		}
		if(tmp3!=1)
			cout<<"k is higher than str1.length()"<<endl;
	}
	return 0;
}
