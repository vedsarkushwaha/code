#include<cstdio>
#include<cstdlib>
#include<vector>
#include<climits>
using namespace std;
int main() {
	int i,j;
	vector<int> vec;
	vector<int>::iterator it;
	//int arr[1000]={0};
	/*for(i=0;i<1000;i++)
		for(j=0;j<1000;j++)
			if(arr[i]!=0) {
				printf("Error");
				printf("%d ",i);
				break;
			}
	*/
	for(it=vec.begin();it!=vec.end();++it)
		printf("%d",*it);
	return 0;
}
