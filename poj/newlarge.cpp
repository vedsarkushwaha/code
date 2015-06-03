#include <iostream>
#include <queue>
#include<cstdio>
using namespace std;
int n;
long long bfs() {
	long long sum;
     queue<long long> p;
     p.push(1);
     while(1) {
		 sum=p.front();
		 if(sum%n==0)
		 	return sum;
		 p.pop();
		 p.push(10*sum);
		 p.push(10*sum+1);
     }
}
int main() {
    while(scanf("%d",&n)!=EOF && n!=0) {
    	printf("%lld\n",bfs());
    }
    return 1;
}
