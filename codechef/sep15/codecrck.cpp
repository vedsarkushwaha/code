#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define UL 1000
#define LL -1000
using namespace std;

double x=sqrt(2);
double y=sqrt(3);
int s;
int kk;
struct block {
	double a,b,c,d;
} mr,ls,un;

void print(block x) {
	pf("%lf %lf\n%lf %lf\n",x.a,x.b,x.c,x.d);
}

block matmul(block x,block y) {
	var(double);
	block z;
	tmp1=x.a*y.a + x.b*y.c;
	tmp2=x.a*y.b+x.b*y.d;
	tmp3=x.c*y.a+x.d*y.c;
	tmp4=x.c*y.b+x.d*y.d;
	z.a=tmp1;
	z.b=tmp2;
	z.c=tmp3;
	z.d=tmp4;
	return z;
}
block blockdiv(block x,int y) {
	x.a=x.a/y;
	x.b=x.b/y;
	x.c=x.c/y;
	x.d=x.d/y;
	return x;
}
block blockmul(block x,int y) {
	x.a=x.a*y;
	x.b=x.b*y;
	x.c=x.c*y;
	x.d=x.d*y;
	return x;
}
int chk(block x) {
	if(x.a>UL || x.b>UL || x.c>UL || x.d>UL) return 1;
	if(x.a<LL || x.b<LL || x.c<LL || x.d<LL) return 2;
	return 0;
}
block power(block x, int y) {
	block temp;
	if(y==0) return un;
	if(y==1) return x;
	temp=power(x, y/2);
	temp=matmul(temp,temp);
	if (y%2==0) {
		return temp;
	}
	else {
		return matmul(x,temp);
	}
}

void fun(int I,int K,double &A,double &B) {
	var(double);
	if(K<I) {
		ls=power(ls,I-K);
		tmp1=ls.a*A+ls.b*B;
		tmp2=ls.c*A+ls.d*B;
		A=tmp1;
		B=tmp2;
	}
	else if(K>I) {
		mr=power(mr,K-I);
		tmp1=mr.a*A+mr.b*B;
		tmp2=mr.c*A+mr.d*B;
		A=tmp1;
		B=tmp2;
	}
}

int main() {
	var(int);
	double val1,val2;
	// init
	mr.a=x-x*y, mr.b=x+x*y, mr.c=x+x*y, mr.d=x*y-x;
	ls.a=(1.0-y)/(8*x), ls.b=(1+y)/(8*x), ls.c=(1+y)/(8*x), ls.d=(y-1.0)/(8*x);
	un.a=1, un.b=0, un.c=0, un.d=1;
	kk=0;
	sc("%d %d %d",&i,&k,&s);
	sc("%lf %lf",&val1,&val2);
	fun(i,k-1,val1,val2);
	double val=x*val1+x*y*val2;
	s--;
	while(s>0) {val=val/2;s--;}
	while(s<0) {val=val*2;s++;}
	pf("%lf\n",val);
	return 0;
}