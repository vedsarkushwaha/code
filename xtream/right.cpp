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
vector<int> vec{5,13,17,25,29,37,41,53,61,73,89,97,101,109,113,125,137,149,157,169,173,181,193,197,229,233,241,257,269,277,281,289,293,313,317,337,349,353,373,389,397,401,409,421,433,449,457,461,509,521,541,557,569,577,593,601,613,617,625,641,653,661,673,677,701,709,733,757,761,769,773,797,809,821,829,841,853,857,877,881,929,937,941,953,977,997,1009};
int chk(int N) {
	var(int);
	fr(i,0,vec.size()) {
		if(N%vec[i]==0)
			return 1;
	}
	return 0;
}
int combi(int l1,int l2) {
	if((l1%l2==0)||(l2%l1==0))
		return 1;
	else
		return 0;
}
int main() {
	var(int);
	int N;
	//print_vec();
	sc("%d",&N);
	while(N--) {
		sc("%d %d",&tmp1,&tmp2);
		if(chk(tmp1)&&chk(tmp2)&&combi(tmp1,tmp2))
			pf("TRUE\n");
		else
			pf("FALSE\n");
	}
	return 0;
}
