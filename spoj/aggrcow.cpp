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
vector<int> vec;

bool chk(int val,int cow) {
	var(int);
	tmp=0,tmp1=0;
	cow--;
	fr(i,1,vec.size()) {
		if(vec[i]-vec[tmp1]>=val) {
			tmp++;
			tmp1=i;
			if(tmp==cow) return 1;
		}
	}
	return 0;
}

int main() {
	var(int);
	int N,C,T;
	sc("%d",&T);
	set<int> st;
	set<int>::iterator it;
	while(T--) {
		sc("%d %d",&N,&C);
		vec.clear();
		st.clear();
		while(N--) {
			sc("%d",&tmp);
			st.insert(tmp);
		}
		for(it=st.begin();it!=st.end();++it) vec.push_back(*it);
		sort(vec.begin(),vec.end());
		if(C==2) pf("%d\n",vec.back()-vec.front());
		else {
			tmp1=vec.front(),tmp3=vec.back();
			while(tmp1<=tmp3) {
				tmp2=(tmp1+tmp3)/2;
				if(chk(tmp2,C)) {
					tmp=tmp2;
					tmp1=tmp2+1;
				}
				else tmp3=tmp2-1;
			}
			pf("%d\n",tmp);
		}
	}
	return 0;
}