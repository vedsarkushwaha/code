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
int get_product_left(vector<int> vec,int ind) {
	var(int);
	tmp3=1;
	if(vec.size()==0)
		return 0;
	if(vec.size()==1)
		return vec[0];
	fr(i,0,ind) {
		tmp3=tmp3*vec[i];
	}
	return tmp3;
}
int get_product_right(vector<int> vec,int ind) {
	var(int);
	if(vec.size()==0)
		return 0;
	if(vec.size()==1)
		return vec[0];
	tmp3=1;
	fr(i,ind+1,vec.size()) {
		tmp3=tmp3*vec[i];
	}
	return tmp3;
}
int get_product(vector<int> vec) {
	var(int);
	if(vec.size()==0)
		return 0;
	tmp3=1;
	if(vec.size()==1)
		return vec[0];
	fr(i,0,vec.size()) {
		tmp3=tmp3*vec[i];
	}
	return tmp3;
}
void print(vector<int> vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf(" %d ",vec[i]);
	}
}
int no_zero(vector<int> vec) {
	var(int);
	int flag;
	vector<int> vec1;
	flag=0;
	if(vec.size()==0)
		return 0;
	if(vec.size()==1)
		return vec[0];
	//vec1.push_back(0);
	tmp=INT_MIN;
	//print(vec);
	fr(i,0,vec.size()) {
		if(vec[i]<0) {
			flag++;
			vec1.push_back(i);
		}
	}
	//vec1.push_back(N-1);
	if(flag%2==0) {
		tmp=get_product(vec);
		//pf("in");
		//print(vec);
	}
	else {
		fr(i,0,vec1.size()) {
			tmp=max(tmp,get_product_left(vec,vec1[i]));
			tmp=max(tmp,get_product_right(vec,vec1[i]));
			//get each negative and print max of left and right
		}
	}
	return tmp;
}
int main() {
	var(int);
	int T,flag=0,N;
	vector<int> vec,vec1;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		vec1.clear();
		vec.clear();
		tmp2=0;
		flag=0;
		tmp3=INT_MIN;
		//vec1.push_back(0);
		fr(i,0,N) {
			sc("%d",&tmp);
			if(tmp==0)
				tmp2=1;
			if(tmp==0) {
				tmp3=max(tmp3,no_zero(vec));
				//pf(" tmp3=%d ",tmp3);
				//pf(" %d ",no_zero(vec));
				vec.clear();
				flag=1;
			}
			else {
				vec.push_back(tmp);
				flag=0;
			}
		}
		tmp1=no_zero(vec);
		if((tmp1<0)&&(tmp2==1))
			tmp1=0;
		if((tmp3<0)&&(tmp2==1))
			tmp3=0;
		if(flag==0)
			pf("%d\n",tmp1);
		else
			pf("%d\n",tmp3);
	}
	
	return 0;
}
