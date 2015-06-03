#include<stdio.h>
int a[2000],b[2000],c[2000];
int lena=0,lenb=0,lenc=1;
void cpy(int *x,int *y,int len) {
	int i;
	for(i=0;i<len;i++)
		x[i]=y[i];
}
void add(int *z,int *y,int *x) {
	int i,c=0,temp;
	for(i=0;i<lenb;i++) {
		temp=y[i]+x[i]+c;
		z[i]=temp%10;
		c=temp/10;
	}
	if(c!=0) {
		z[i]=c;
		lenc++;
	}
}
void prnt() {
	int i;
	for(i=lenc-1;i>=0;i--)
		printf("%d",c[i]);
}
int main() {
	a[0]=0,b[0]=0,c[0]=1;
	int i=1;
	while(lenc<1000) {
		cpy(a,b,lenb);
		lena=lenb;
		cpy(b,c,lenc);
		lenb=lenc;
		add(c,b,a);
		i++;
		printf("%d ",i);
		prnt();
		printf("\n");
	}
	return 0;
}
