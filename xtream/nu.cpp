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
void print(vector<int> vec) {
	var(int);
	fr(i,0,vec.size()) {
		if(i==vec.size()-1)
		pf("%d",vec[i]);
		else
		pf("%d ",vec[i]);
	}
}
void print_pad(int n) {
	var(int);
	fr(i,0,n)
		pf(".");
}
int len(int x) {
	var(int);
	tmp=0;
	while(x!=0) {
		tmp++;
		x=x/10;
	}
	return tmp;
}
int main() {
	var(int);
	int K;
	string str;
	vector<int> vec[20];
	char top[300];
	char *tt;
	//sc("%d",&K);
	//pf("%d ",K);
	//input
	/*vec[0].push_back(1);vec[0].push_back(1);
	vec[0].push_back(1);vec[0].push_back(1);
	vec[0].push_back(1);vec[0].push_back(1);
	vec[0].push_back(1);vec[0].push_back(1);
	vec[0].push_back(1);vec[0].push_back(1);*/
	//input
	//pf("2");
	int arr[20]={0};
	scanf("%[^\n]s",top);
	//pf("%s\n",top);
	tt=strtok(top," ");
	tmp3=0;
	fflush(stdout);
	while(tt!=NULL) {
		//pf("%s\n",tt);
		if(tmp3==0) {
			tmp3=1;
			K=atoi(tt);
			//pf("%d ",K);
		}
		else {
			vec[0].push_back(atoi(tt));
			//pf("%d ",vec[0].back());
		}
		tt=strtok(NULL," ");
		//fflush(stdout);
	}
	fr(i,1,K+1) {
		j=0;
		do {
			tmp1=1;
			if(j==vec[i-1].size()-1) {
				vec[i].push_back(tmp1);vec[i].push_back(vec[i-1].at(j));
			}
			else {
				while(vec[i-1].at(j)==vec[i-1].at(j+1)) {
					j+=1;tmp1++;
					if(j>=vec[i-1].size()-1)
						break;
				}
				vec[i].push_back(tmp1);vec[i].push_back(vec[i-1].at(j));
			}
			j++;
		}while(j<vec[i-1].size());
	}
	tmp1=0;
	fr(i,0,K+1) {
		tmp=0;
		//print(vec[i]);
		//tmp=max(tmp,int(vec[i].size()));
		fr(j,0,vec[i].size()) {
			tmp+=len(vec[i][j]);
		}
		//pf("%d\n",tmp);
		arr[i]=tmp+vec[i].size()-1;
		tmp1=max(tmp1,arr[i]);
		//pf("\n");
	}
	//pf(" %d ",tmp1);
	fr(i,0,K+1) {
		if((tmp1-arr[i])%2==1)
			print_pad((tmp1-arr[i])/2+1);
		else
			print_pad((tmp1-arr[i])/2);
		print(vec[i]);
		print_pad((tmp1-arr[i])/2);
		pf("\n");
	}
	pf("%d\n",int(vec[K].size()));
	return 0;
}
