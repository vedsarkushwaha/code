#include<cstdio>
#include<cmath>
using namespace std;
int main() {
    int N,Q;
    long long x,y;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++) {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&Q);
    while(Q--) {
        scanf("%lld%lld",&x,&y);
        if(x>y)
            printf("Odd\n");
        else if(arr[x]==0)
        	printf("Odd\n");
       	else if((arr[x-1]&1)==1)
        	printf("Odd\n");
        else
        	printf("Even\n");
    }
    return 0;
}
