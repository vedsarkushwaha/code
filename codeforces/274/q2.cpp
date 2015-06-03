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
void print_vec(vector<int> vec) {
	var(int);
	fr(i,0,vec.size())
		pf("%d ",vec.at(i));
}
struct node {
	int a,b;
};
int main() {
	queue<node> st;
	node tt;
	var(int);
	int N,K;
	vector<int> vec;
	sc("%d %d",&N,&K);
	fr(i,0,N) {
		sc("%d",&tmp);
		vec.push_back(tmp);
	}
	tmp3=0;
	tmp=0;
	while(K--) {
		//print_vec(vec);
		//pf("\n");
		tmp1=max_element(vec.begin(),vec.end())-vec.begin();
		tmp2=min_element(vec.begin(),vec.end())-vec.begin();
		if((vec.at(tmp1)-vec.at(tmp2)==0)||(vec.at(tmp1)-vec.at(tmp2)==1)) {
			break;
		}
		else {
			tmp++;
			//pf("%d %d\n",tmp1+1,tmp2+1);
			tt.a=tmp1+1;tt.b=tmp2+1;
			st.push(tt);
			vec.at(tmp1)=vec.at(tmp1)-1;
			vec.at(tmp2)=vec.at(tmp2)+1;
		}
		//pf("%d %d\n",tmp1,tmp2);
	}
	if(tmp3==0) {
		tmp1=max_element(vec.begin(),vec.end())-vec.begin();
		tmp2=min_element(vec.begin(),vec.end())-vec.begin();
		pf("%d %d\n",vec.at(tmp1)-vec.at(tmp2),tmp);
	}
	while(!st.empty()) {
		tt=st.front();
		st.pop();
		pf("%d %d\n",tt.a,tt.b);
	}
	return 0;
}
