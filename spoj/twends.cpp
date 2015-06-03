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
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,T,N
using namespace std;
unsigned ll power(unsigned ll x,unsigned ll y) {
	unsigned ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
unsigned ll gcd(unsigned ll a, unsigned ll b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int main() {
	var(int);
	vector<int> vec;
	while(1) {
		vec.clear();
		sc("%d",&N);
		k+=1;
		if(N==0)
			break;
		int mat[N][N];
		tmp2=0;
		fr(i,0,N) {
			sc("%d",&tmp);
			vec.push_back(tmp);
			tmp2+=tmp;
			mat[i][i]=vec[i];
		}
		fr(i,0,N-1)
			mat[i][i+1]=max(vec[i],vec[i+1]);
		fr(i,2,N) {
			fr(j,0,N-i) {
				tmp=vec[j];
				if(vec[j+1]>=vec[j+i])
					tmp+=mat[j+2][i+j];
				else
					tmp+=mat[j+1][j+i-1];
				tmp1=vec[j+i];
				if(vec[j]>=vec[j+i-1])
					tmp1+=mat[j+1][j+i-1];
				else
					tmp1+=mat[j][i+j-2];
				//if (j==1&&j+i==3)
					//pf(" %d %d ",tmp,tmp1);
				mat[j][i+j]=max(tmp,tmp1);
			}
		}
		/*pf("\n");
		fr(i,0,N) {
			fr(j,0,N) {
				if(j<i)
					pf("0 ");
				else
					pf("%d ",mat[i][j]);
			}
			pf("\n");
		}*/
		tmp1=mat[0][N-1];
		tmp2=tmp2-tmp1;
		tmp3=tmp1-tmp2;
		//pf("%d %d %d\n",tmp1,tmp2,tmp3);
		pf("In game %d, the greedy strategy might lose by as many as %d points.\n",k,tmp3);
	}
	return 0;
}
