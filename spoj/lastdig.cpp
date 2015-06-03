#include<cstdio>
#define sc scanf
#define pf printf
using namespace std;
int main() {
	int a,b,T,tmp;
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&a,&b);
		tmp=b%4;
		if(b==0)
			pf("1\n");
		else if((a%10==0)||(a%10==1)||(a%10==5)||(a%10==6))
			pf("%d\n",a%10);
		else if(a%10==2) {
			if(tmp==0)
				pf("6\n");
			else if(tmp==1)
				pf("2\n");
			else if(tmp==2)
				pf("4\n");
			else if(tmp==3)
				pf("8\n");
		}
		else if(a%10==3) {
			if(tmp==0)
				pf("1\n");
			else if(tmp==1)
				pf("3\n");
			else if(tmp==2)
				pf("9\n");
			else if(tmp==3)
				pf("7\n");
		}
		else if(a%10==4) {
			tmp=tmp%2;
			if(tmp==0)
				pf("6\n");
			else
				pf("4\n");
		}
		else if(a%10==7) {
			if(tmp==0)
				pf("1\n");
			else if(tmp==1)
				pf("7\n");
			else if(tmp==2)
				pf("9\n");
			else if(tmp==3)
				pf("3\n");
		}
		else if(a%10==8) {
			if(tmp==0)
				pf("8\n");
			else if(tmp==1)
				pf("4\n");
			else if(tmp==2)
				pf("2\n");
			else if(tmp==3)
				pf("6\n");
		}
		else if(a%10==9) {
			tmp=tmp%2;
			if(tmp==0)
				pf("1\n");
			else
				pf("9\n");
		}
	}
	return 0;
}
