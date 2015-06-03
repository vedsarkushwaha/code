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
#define MX 10000000
using namespace std;
struct node {
	int w;
	int num;
};
unsigned ll power(unsigned long long x,unsigned long long y) {
	unsigned ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
int sumvec(vector<int> vec) {
	int sum=0;
	int i;
	fr(i,0,vec.size()) {
		if(vec[i]<0)
			continue;
		else
			sum+=vec[i];
	}
	return sum;
}

int main() {
	var(int);
	int N,T,sum=0;
	node tt;
	vector<node> vec;
	vector<int> sol;
	sc("%d %d",&N,&T);
	fr(i,0,N) {
		sc("%d",&tmp);
		tt.w=tmp;
		tt.num=1;
		vec.push_back(tt);
	}
	//solve one
	while(vec.size()!=1) {
		tmp=0;
		fr(i,0,vec.size()) {
			if(vec[i].w==1) {
				tmp=1;
				if(i==vec.size()-1) {
					//if last element then move it earlier
					tmp2=(vec[i].w)*(vec[i].num)+(vec[i-1].w)*(vec[i-1].num);
					sum+=tmp2;
					sol.push_back(tmp2);
					vec[i-1].num+=1;
					vec[i-1].w+=vec[i].w;
					vec.erase(vec.begin()+i);
				}
				else {
					tmp2=(vec[i].w)*(vec[i].num)+(vec[i+1].w)*(vec[i+1].num);
					sum+=tmp2;
					sol.push_back(tmp2);
					vec[i].num+=1;
					vec[i].w+=vec[i+1].w;
					vec.erase(vec.begin()+i+1);
				}
			}
		}
		if(tmp==0)
			break;
	}
	//solve the problem
	while(vec.size()!=1) {
		tmp=0;
		fr(i,0,vec.size()-1) {
			tmp3=abs(vec[i].w-vec[i].num)+abs(vec[i+1].w-vec[i+1].num);
			if(tmp3>tmp) {
				tmp=tmp3;
				tmp1=i;
				tmp2=(vec[i].w)*(vec[i].num)+(vec[i+1].w)*(vec[i+1].num);
			}
		}
		sum+=tmp2;
		sol.push_back(tmp2);
		vec[tmp1].num+=1;
		vec[tmp1].w+=vec[tmp1+1].w;
		vec.erase(vec.begin()+tmp1+1);
	}
	tmp2=0;
	while(sum>T) {
		fr(i,0,N-1) {
			sol[i]-=1;
		}
		tmp2++;
		sum=sumvec(sol);
	}
	pf("%d",tmp2);
	return 0;
}
