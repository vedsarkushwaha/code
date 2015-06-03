#include<cstdio>
using namespace std;
int main() {
	int T,X,Y;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&X,&Y);
		//printf("%d%d",X,Y);
		if((X==0)&&(Y==0))
			printf("YES\n");
		else if(((X%2==1)&&(X>0))&&((Y>=(1-X))&&(Y<=(X+1)))) {
			//printf("a");
			//if((Y>=(1-X))&&(Y<=(X+1)))
				printf("YES\n");
			//else
				//printf("NO\n");
		}
		else if(((X<0)&&(X%2==0))&&((Y>=X)&&(Y<=-X))) {
			//printf("2");
			//if((Y>=X)&&(Y<=-X))
				printf("YES\n");
			//else
				//printf("NO\n");
		}
		else if(((Y>0)&&(Y%2==0))&&((X>=-Y)&&(X<=(Y-1)))) {
			//printf("3");
			//if((X>=-Y)&&(X<=(Y-1)))
				printf("YES\n");
			//else
				//printf("NO\n");
		}
		else if(((Y<0)&&(Y%2==0))&&((X>=Y)&&(X<=(1-Y)))) {
			//printf("4");
			//if((X>=Y)&&(X<=(1-Y)))
				printf("YES\n");
			//else
				//printf("NO\n");
		}
		else {
			//printf("2");
			printf("NO\n");
		}
	}
	return 0;
}
