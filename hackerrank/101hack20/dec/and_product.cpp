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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T,N
#define push_back pb
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pii>
using namespace std;

int chk(unsigned int num) {
	var(unsigned int);
	i=1;
	tmp=0;
	while(i>0) {
		//pf("%u ",i);
		if(num&i) {
			tmp=i;
			//pf("%u\n",i);
		}
		i=i<<1;
	}
	return tmp;
}
int main() {
	var(unsigned int);
	sc("%u",&T);
	while(T--) {
		tmp=0,tmp3=0;
		//tmp=~tmp;
		sc("%u %u",&tmp1,&tmp2);
		//chk last bit
		//pf(" n ");
		//pf("%u ",chk(tmp1));
		//pf("%u ",chk(tmp2));
		if(chk(tmp1)!=chk(tmp2)) {
			//pf("%u %u\n",chk(tmp1),chk(tmp2));
			pf("0\n");
		}
		else {
			//chk whole series
			tmp=tmp1;
			i=1;
			while(i>0) {
				//pf("%u %u %u\n",tmp2,tmp1+i,i);
				if(tmp2-tmp1>=i) {
					//pf("ee");
					tmp=tmp&(~i);
				}
				else
					break;
				i=i<<1;
				//pf	("%u ",i);
			}
			pf("%u\n",tmp);
		}
	}
	return 0;
}
