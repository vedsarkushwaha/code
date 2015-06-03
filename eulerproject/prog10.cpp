#define sz 10000000
#include<cstdio>
#include<cmath>
#include<vector>
#define sc scanf
#define pf printf
using namespace std;
typedef unsigned long long ull;
int prm[sz+1];
void init() {
	int i;
	for(i=0;i<=sz;i++)
		prm[i]=1;
	prm[0]=0;
	prm[1]=0;
}
void seive_fun() {
	int i,j,k,limit;
	//init();
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}
struct node {
	ull sum;
	int ind;
};
vector<node> vec;
void prnt_arr() {
	int i;
	node temp;
	temp.sum=0;temp.ind=0;
	vec.push_back(temp);
	for(i=1;i<=sz;i++) {
		temp.ind=i;
		if(prm[i]==0) {
			temp.sum=(vec.back()).sum+i;
		}
		else {
			temp.sum=(vec.back()).sum;
		}
		vec.push_back(temp);
	}
}
int main() {
	seive_fun();
	prnt_arr();
	int T,N;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		pf("%llu\n",(vec.at(N)).sum);
	}
	return 0;
}
