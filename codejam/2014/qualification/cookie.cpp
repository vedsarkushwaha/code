#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(double);
	double C,F,X;
	tmp5=0;
	int f_no=0,_T,_i;
	sc("%d",&_T);
	fr(_i,1,_T+1) {
		f_no=0,tmp5=0;
		sc("%lf %lf %lf",&C,&F,&X);
		while(1) {
			if((X/(2.0+f_no*F))<= (C/(2.0+f_no*F))+X/((f_no+1)*F+2.0)) {
				tmp5+=(X/(2.0+f_no*F));
				break;
			}
			else {
				tmp5+=C/(2.0+f_no*F);
				f_no+=1;
			}
		}
		pf("Case #%d: %.7lf\n",_i,tmp5);
	}
	return 0;
}