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

int main() {
	var(int);
	int T,N;
	vector<int> vec,revvec;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		int inc[N+1];int dec[N+1];
		inc[0]=0;dec[0]=0;
		fr(i,0,N) {
			inc[i]=1;dec[i]=1;
		}
		fr(i,0,N) {
			sc("%d",&tmp);
			vec.push_back(tmp);
		}
		fr(i,1,N+1) {
			fr(j,0,i) {
				if(vec[j]<vec[i])
					inc[i]=max(1+inc[j],inc[i]);
			}
		}
		revvec=vec;
		reverse(revvec.begin(),revvec.end());	
		fr(i,1,N+1) {
			fr(j,0,i) {
				if(revvec[j]>revvec[i])
					dec[i]=max(1+dec[j],dec[i]);
			}
		}
		/*fr(i,0,N)
			pf("%d ",vec[i]);
		pf("\n");
		fr(i,0,N)
			pf("%d ",inc[i]);
		pf("\n");
		fr(i,0,N)
			pf("%d ",dec[i]);*/
		tmp=0;
		fr(i,1,N+1) {
			if(dec[i]+inc[i]>tmp) {
				tmp=dec[i]+inc[i];
				tmp1=i;
			}
		}
		fr(i,0,tmp1+1) {
			
		vec.clear();revvec.clear();
	}
	return 0;
}
