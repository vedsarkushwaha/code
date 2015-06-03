#include<cstdio>
#include<cmath>
using namespace std;
unsigned long long tabl[201];
void init() {
	int i;
	tabl[0]=1;tabl[2]=1;tabl[4]=2;
	for(i=6;i<=200;i+=2)
		tabl[i]=0;
}

void build_table(int x) {
	int i,j;
	if(tabl[x]==0) {
		for(i=0;i<=x-2;i+=2) {
			if(tabl[i]==0) {
				build_table(i);
			}
			else if(tabl[x-i-2]==0)
				build_table(x-i-2);
			tabl[x]+=tabl[i]*tabl[x-i-2];
		}
	}
}

int main() {
	int n;
	init();
	while((scanf("%d",&n)!=EOF)&&(n!=-1)) {
		build_table(2*n);
		printf("%lld\n",tabl[2*n]);
	}
	return 0;
}
