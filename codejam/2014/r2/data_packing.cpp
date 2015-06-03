#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int T,X,N,i,j,k,itm,cnt;
	vector<int> arr;
	scanf("%d",&T);
	for(i=0;i<T;i++) {
		cnt=0;
		arr.clear();
		scanf("%d%d",&N,&X);
		for(j=0;j<N;j++) {
			scanf("%d",&itm);
			arr.push_back(itm);
		}
		sort(arr.begin(),arr.end());
		j=0;k=N-1;
		while(j<k) {
			if(arr[j]+arr[k]<=X) {
				j++;k--;cnt++;
			}
			else {
				cnt++;k--;
			}
		}
		if(j==k)
			printf("Case #%d: %d\n",i+1,cnt+1);
		else
			printf("Case #%d: %d\n",i+1,cnt);
	}
	return 0;
}
