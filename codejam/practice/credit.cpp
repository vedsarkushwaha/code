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
#define LL long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

int main() {
	var(long int);
	vector<long int> vec;
	vector<long int>::iterator it;
	long int N,C,P,I;
	sc("%ld",&N);
	fr(i,1,N+1) {
		sc("%ld",&C);
		sc("%ld",&I);
		vec.clear();
		while(I--) {
			sc("%ld",&tmp);
			vec.push_back(tmp);
		}
		fr(j,0,vec.size()-1) {
			tmp=vec[j];
			tmp1=C-vec[j];
			//pf(" %ld ",*(vec.begin()+j));
			if((it=find(vec.begin()+j+1,vec.end(),tmp1))!=vec.end()) {
				pf("Case #%ld: %ld %ld\n",i,j+1,(it-vec.begin())+1);
				break;
			}
		}
	}
	return 0;
}