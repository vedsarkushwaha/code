#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
void print(vector<int> vec) {
	int i;
	for(i=0;i<vec.size();i++)
		printf("%d ",vec[i]);
}
int main() {
	int arr[9]={1,2,3,4,5,6,7,8,9};
	int i,j,k,sm,cnt=0;
	vector<int> vec;
	for(i=1;i<pow(2,9);i++) {
		sm=0;
		//get set bits
		vec.clear();
		for(j=0;j<9;j++) {
			if((i&(1<<j))!=0) {
				sm+=arr[j];
				//printf("Enter");
				vec.push_back(arr[j]);
			}
		}
		//printf("%d-",vec.size());
		if(sm%2==0) {
			cnt++;
			//print(vec);
			//printf("\n");
		}
	}
	printf("%d",cnt);
	return 0;
}
