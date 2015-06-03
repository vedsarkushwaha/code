#define sz 1000000
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int prm[sz+1];

int bin_search(vector<int> arr,int low,int high,int ele) {
	int mid;
	while(low<=high) {
		mid=(low+high)/2;
		if(arr[mid]==ele)
			return mid;
		else if(ele<arr[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
void seive_fun() {
	int i,j,k,limit;
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
int main() {
	vector<int> pr;
	vector<int>::iterator it1,it2;
	seive_fun();
	int i,j,k,T,L,R,cnt;
	prm[4]=0;
	for(i=2;i<=sz;i++) {
		if(prm[i]==0)
			pr.push_back(i);
	}
	scanf("%d",&T);
	while(T--) {
		cnt=0;
		scanf("%d %d",&L,&R);
		i=L;
		j=R;
		it1=lower_bound(pr.begin(),pr.end(),i);
		it2=upper_bound(pr.begin(),pr.end(),j);
		it2--;
		//printf("%d %d\n",*it1,*it2);
		if(*it1>*it2)
			printf("0\n");
		else {
			printf("%d\n",(R-L+1)-(*it2-*it1));
		}
	}
	return 0;
}
