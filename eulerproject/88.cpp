#include <cstdio>
#include <vector>
#include <numeric>
#include <limits>
#include <set>
#define ll long long

using namespace std;

int arr[40010];
vector<int> vec;

void print(vector<int> vec) {
	int i;
	for(i=0;i<vec.size();i++) {
		printf("%d ",vec[i]);
	}
	printf("\n");
}
int prod(vector<int> vec) {
	int i,tmp=1;
	for(i=0;i<vec.size();i++) {
		tmp*=vec[i];
	}
	return tmp;
}
int sum(vector<int> vec) {
	int i,tmp=0;
	for(i=0;i<vec.size();i++) {
		tmp+=vec[i];
	}
	return tmp;	
}

int getK(int factorCount, int factorProduct, int factorSum) {
	return factorProduct - factorSum + factorCount;
}

void allFactors(int num) {
	int i;
	// if all factors are calculated
	if(num==1) {
		int p = prod(vec);
		int s = sum(vec);
		int k=getK(vec.size(), p, s);
		arr[k]=min(arr[k], p);
		return;
	}
	for(i=2;i<=num;i++) {
		if(num%i==0) {
			vec.push_back(i);
			allFactors(num/i);
			vec.pop_back();
		}
	}
}

int main() {
	int i;
	int limit = 12;
	set<int> st;
	// init
	for(i=0;i<12010;i++) {
		arr[i]=INT_MAX;
	}

	for(int i=2;i<=2*limit;i++) {
		allFactors(i);
	}
	for(int i=2;i<=limit;i++) {
		// printf("%d %d\n",i,arr[i]);
		st.insert(arr[i]);
	}
	printf("%d\n",accumulate(st.begin(),st.end(),0));
	return 0;
}