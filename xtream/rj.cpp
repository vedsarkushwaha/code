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
struct node {
	int a,b;
};
bool comp(node x,node y) {
	return x.b<y.b;
}
int arr[10000]={0};
int main() {
	var(int);
	int N,M;
	vector<node> vec;
	vector<node>::iterator it1,it2,it3;
	node temp;
	sc("%d %d",&N,&M);
	while(M--) {
		sc("%d %d",&tmp,&tmp1);
		temp.a=tmp;temp.b=tmp1;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end(),comp);
	while(N--) {
		sc("%d",&tmp1);
		temp.b=tmp1;temp.a=0;
		it1=lower_bound(vec.begin(),vec.end(),temp,comp);
		//pf("%d %d\n",it1->a,it1->b);
		//it2=upper_bound(vec.begin(),vec.end(),temp,comp);
		//pf("%d %d\n",it2->a,it2->b);
		if(it1->b==tmp1)
			for(it3=it1;it3->b==tmp1;++it3) {
				//pf("%d %d\n",it3->a,arr[it3->a]);
				if(arr[it3->a]!=1) {
					pf("NO\n");
					//while(N--) {sc("%d",&tmp);}
					//break;
					return 0;
					//pf NO and return
				}
			}
		arr[tmp1]=1;
	}
	//pf yes
	pf("YES\n");
	return 0;
}
