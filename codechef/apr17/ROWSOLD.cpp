#include <cstdio>
#include <string>
#include <iostream>

#define ll long long
using namespace std;

int main() {
	int T;
	scanf("%d\n",&T);
	while(T--) {
		string N;
		cin>>N;
		long long ans=0;
		
		// count cluster and its size
		int i=N.length()-1;
		ll clusterSize=0;
		ll clusterCnt=0;
		ll zeroCnt=0;
		while(i>=0 && N[i]=='1') {
			i--;
		}
		for(;i>=0;i--) {
			if(N[i]=='1') {
				clusterSize=0;
				clusterCnt++;
				while(i>=0 && N[i]=='1') {
					i--;
					clusterSize++;
				}
				i++;
				ans+=clusterSize*clusterCnt;
				// printf("%d, ",ans);
				ans+=clusterSize*zeroCnt;
				// printf("%d %d, ",ans,zeroCnt);
			}
			else zeroCnt++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}