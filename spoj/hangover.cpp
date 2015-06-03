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

int calc(double p) {
	var(double);
	int cnt=0;
	tmp=0;
	while(tmp<p) {
		cnt++;
		//pf("1\n");
		tmp+=(1/((double)cnt+1));
	}
	return cnt;
}
int main() {
	var(double);
	vector<int> vec;
	/*for(i=0;i<5.3;i=i+0.01) {
		vec.push_back(calc(i));
	}*/
	while(1) {
		sc("%lf",&tmp);
		if(tmp==0.00)
			break;
		//pf("%d card(s)\n",vec[int(tmp*100)]);
		pf("%d card(s)\n",calc(tmp));
	}
	return 0;
}
