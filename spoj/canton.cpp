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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
using namespace std;
struct ele {
	int n,d;
};
ele mat[10000][10000];
int main() {
	var(int);
	vector<ele> vec;
	ele ndtmp;
	fr(i,0,3600) {
		fr(j,0,3600) {
			mat[i][j].n=i+1;mat[i][j].d=j+1;
		}
	}
	//pritn mat
	/*fr(i,0,10) {
		fr(j,0,10) {
			pf("%d/%d ",mat[i][j].n,mat[i][j].d);
		}
		pf("\n");
	}*/
	sc("%d",&T);
	i=0;j=1;
	vec.push_back(mat[0][0]);
	tmp3=2;
	//vec.push_back(mat[i][j]);
	while(tmp3<10000001) {
		if(i==0) {
			while(j!=0) {
				vec.push_back(mat[i][j]);
				i++;j--;
				tmp3++;
			}
			vec.push_back(mat[i][j]);
			i++;
		}
		if(j==0) {
			while(i!=0) {
				vec.push_back(mat[i][j]);
				i--;j++;
				tmp3++;
			}
			vec.push_back(mat[i][j]);
		}
		j++;
	}
	//print vector
	/*fr(i,0,20) {
		pf("%d/%d ",vec[i].n,vec[i].d);
	}*/
	while(T--) {
		sc("%d",&tmp);
		pf("TERM %d IS %d/%d\n",tmp,vec[tmp-1].n,vec[tmp-1].d);
	}
	return 0;
}
