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

int main() {
	var(ll);
	//generate series
	/*vector<ll> vec;
	tmp=1;
	fr(i,1,1000000000) {
		tmp1=((2*i-2)*(2*i-1))/2;
		tmp2=((i-1)*i)/2;
		vec.push_back(2*(tmp1-tmp2)+(2*i-1));
	}*/
	while(1) {
		sc("%lld",&T);
		if(T==-1)
			break;
		if((T==1)||(T==7))
			pf("Y\n");
		else if(T<15)
			pf("N\n");
		else {
			if((T-1)%3!=0) {
				pf("N\n");
			}
			else {
				tmp3=0;
				fr(i,2,100000) {
					tmp=i*(i-1);
					tmp1=(T-1)/3;
					if(tmp==tmp1) {
						pf("Y\n");
						tmp3=1;
						break;
					}
				}
				if(tmp3==0)
					pf("N\n");
			}
		}
	}	
	return 0;
}