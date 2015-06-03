#include<cstdio>
#include<cmath>
#define sc scanf
double a[20][20];
int m;
double determinant(double f[20][20],int);
int main() {
	int T;
	double tmp,tmp1,tmp2,tmp3,tmp4,tmp5;
	sc("%d\n",&T);
	while(T--) {
		int i,j;
		m=5;
		for(i=1;i<=m;i++)
			for(j=1;j<=m;j++)
				//sc("%lf",&a[i][j]);
				if(i==j)
					a[i][j]=0;
				else
					a[i][j]=1;
		sc("%lf %lf %lf %lf %lf %lf",&tmp,&tmp1,&tmp2,&tmp3,&tmp4,&tmp5);
		a[2][3]=tmp*tmp,a[2][4]=tmp1*tmp1,a[2][5]=tmp2*tmp2,a[3][4]=tmp3*tmp3,a[3][5]=tmp4*tmp4,a[4][5]=tmp5*tmp5;
		a[3][2]=a[2][3],a[4][2]=a[2][4],a[5][2]=a[2][5],a[4][3]=a[3][4],a[5][3]=a[3][5],a[5][4]=a[4][5];
		/*for(i=1;i<m+1;i++) {
			for(j=1;j<m+1;j++) {
				printf("%.0lf\t",a[i][j]);
			}
			printf("\n");
		}*/
		printf("%.4lf\n",sqrt(determinant(a,m)/288.0));
		//printf("%.4lf\n",determinant(a,m));
	}
}
double determinant(double f[20][20],int x) {
	int t;
	int j,p,q;
	double c[20],b[20][20],d=0,pr;
	if(x==2) {
		d=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
		return(d);
	}
	else {
		for(j=1;j<=x;j++) {
			int r=1,s=1;
			for(p=1;p<=x;p++) {
				for(q=1;q<=x;q++) {
					if(p!=1&&q!=j) {
						b[r][s]=f[p][q];
						s++;
						if(s>x-1) {
							r++;
							s=1;
						}
					}
				}
			}
			for(t=1,pr=1;t<=(1+j);t++)
				pr=(-1)*pr;
			c[j]=pr*determinant(b,x-1);
		}
		for(j=1,d=0;j<=x;j++) {
			d=d+(f[1][j]*c[j]);
		}
		return(d);
	}
}
