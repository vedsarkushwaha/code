#include<stdio.h>
#define mod 1000000007
typedef unsigned long long ll;
using namespace std;
int main()
{
	int aa[100];
	int t,i;
	long long c,n,fa,fb,a,b,temp;
	scanf("%d",&t);
	while(t--)
    {	//printf("%d\n",t);	
		scanf("%lld",&n);
		//printf("%lld\n",n);
		a=0;fa=0;b=1;fb=1;
		n=n*2;
		c=n;
		i=0;
		while(c){
			aa[i]=(c%2);
			i++;
			c=c/2;
		}
		//for(int h=1;h<=i;h++) printf("\t%d",aa[h]);
		i=i-1;
		//printf("%lld\t%d\t",n,i);
		while(i--){
			temp=fb;
			fb=((2*fa+fb)*fb)%mod;
			fa=(fa*fa+temp*temp)%mod;
			if(aa[i]){  //printf("hfhfhhf");
				temp=fb;
				fb=fa+fb;
				fa=temp;
			}
			//i--;
		}
		printf("%lld\n",((fa+fb)*(fb))%mod);
	}
	return 0;
}