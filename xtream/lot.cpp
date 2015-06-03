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
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
int digi_len(int num) {
	var(int);
	while(num!=0) {
		tmp++;
		num=num/10;
	}
	return tmp;
}
void print_vec(vector<int> vec) {
	var(int);
	fr(i,0,vec.size())
		pf("%d ",vec[i]);
}
int main() {
	var(int);
	int S,E,P,N;
	vector<int> vec;
	sc("%d %d %d %d",&S,&E,&P,&N);
	fr(i,0,N) {
		sc("%d",&tmp);
		vec.push_back(tmp);
		j=1;
		k=pow(10,digi_len(tmp));
		while(((tmp1=j*k+tmp)<=E)&&((tmp1=j*k+tmp)>=S)) {
			vec.push_back(j*k+tmp);
			j++;
		}
		j=1;
		while(1) {
			tmp2=pow(10,j);
			tmp1=tmp*tmp2;
			if((tmp1+k<=E)&&(tmp1+k>=S))
				vec.push_back(tmp1);
			fr(k,1,tmp2) {
				if((tmp1+k<=E)&&(tmp1+k>=S))
					vec.push_back(tmp1+k);
			}
			if(tmp1+k>E)
				break;
			j++;
		}
	}
	sort(vec.begin(),vec.end());
	//lower_bound(vec.begin(),vec.end(),);
	vector<int>::iterator it;
	it=upper_bound(vec.begin(),vec.end(),E);
	if(it!=vec.end()) {
		vec.erase(it,vec.end());
	}
	//print_vec(vec);
	if(P<vec.size())
		pf("%d\n",vec.at(P-1));
	else
		pf("DOES NOT EXIST\n");
	return 0;
}
