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
using namespace std;

double fun(double A,double B, double C, double D, vector<double> &x, vector<double> &y, vector<double> &z) {
	var(int);
	int N=x.size();
	double num=0,dem=0,sm=0;
	fr(i,0,N) {
		fr(j,0,N) {
			if(i==j) continue;
			double dx=x[i]-x[j],dy=y[i]-y[j],dz=z[i]-z[j];
			num=abs(A*dx+B*dy+C*dz+D);
			dem=sqrt(dx*dx*dx*dx+dy*dy*dy*dy+dz*dz*dz*dz);
			double tmp=num/dem;
			tmp=tmp/N;
			tmp=tmp/(N-1);
			sm+=tmp;
		}
	}
	return sm;
}

int main() {
	var(int);
	int N,Q;
	sc("%d %d",&N,&Q);
	vector<double> a,b,c;
	double p,q,r,A,B,C,D;
	fr(i,0,N) {
		sc("%lf %lf %lf",&p,&q,&r);
		a.pb(p);
		b.pb(q);
		c.pb(r);
	}
	fr(i,0,Q) {
		sc("%lf %lf %lf %lf",&A,&B,&C,&D);
		pf("%lf\n",fun(A,B,C,D,a,b,c));
	}
	return 0;
}
