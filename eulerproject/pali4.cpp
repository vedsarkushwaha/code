#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int chk_pall(int x) {
	int a[6],i=0,j,k;
	while(x!=0) {
		a[i]=x%10;
		x=x/10;
		i++;
	}
	for(k=0,j=i-1;k<j;k++,j--) {
		if(a[k]!=a[j])
			return 0;
	}
	return 1;
}
int main() {
	int i=999,j=999,temp,a[2500],p=0,max=0,T,N;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		i=j=999;max=0;
		while(i>99) {
			while(j>99) {
				temp=i*j;
				if((temp<N)&&(chk_pall(temp))) {
					if(max<temp)
						max=temp;
				}
				j--;
			}
			i--;
			j=999;
		}
		printf("%d\n",max);
	}
	return 0;
}
