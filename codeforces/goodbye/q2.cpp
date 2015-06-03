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
#define pb push_back
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pii>
using namespace std;

int main() {
	var(int);
	vi vec;
	string str[310];
	queue<int> Q;
	int arr[310]={0};
	sc("%d",&N);
	while(N--) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	fr(i,0,vec.size()) {
		cin>>str[i];
	}
	i=0;
	fr(i,0,vec.size()) {
		if(vec[i]<=i+1)
			continue;
		//chk poss
		tmp3=0;
		fr(j,0,310)
			arr[j]=0;
		//Q.clear();
		Q.push(i);
		while(!Q.empty()) {
			tmp1=Q.front();
			arr[tmp1]=1;
			fr(j,0,str[tmp1].size()) {
				if((arr[j]==1)||(j<i))
					continue;
				if(str[tmp1][j]=='1') {
					//pf("\n%d %d\n",tmp1,j);
					if(vec[j]<vec[i]) {
						//fininsh
						//pf(" %d %d %d\n",vec[j],vec[i],tmp1);
						//pf("%d %d\n",vec[j],vec[i]);
						while(!Q.empty()) {
							swap(vec[j],vec[Q.front()]);
							j=Q.front();
							Q.pop();
						}
						//swap(vec[i],vec[tmp1]);
						fr(k,0,vec.size())
							pf("%d ",vec[k]);
						return 0;
					}
					Q.push(j);
				}
			}
			Q.pop();
		}
	}
	fr(k,0,vec.size())
		pf("%d ",vec[k]);
	return 0;
}
