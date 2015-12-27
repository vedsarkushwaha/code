#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(long double);
	long double x1,y1,r1,x2,y2,r2;
	cin>>x1>>y1>>r1;
	cin>>x2>>y2>>r2;
	tmp=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	cout.precision(17);
	// cout<<r1<<" "<<r2<<" "<<tmp<<endl;
	// cout<<tmp<<endl;
	if(tmp>=r1+r2) {
		cout<<"0.00";
		return 0;
	}

	if(tmp==0) {
		cout<<M_PI*min(r1,r2)*min(r1,r2);
		return 0;
	}
	if(r1<r2) {
		if(r1+tmp<=r2) {
			cout<<M_PI*r1*r1;
			return 0;
		}
	}
	if(r2<r1) {
		if(r2+tmp<=r1) {
			cout<<M_PI*r2*r2;
			return 0;
		}
	}

	tmp4 = (r2*r2 + tmp*tmp - r1*r1);
	tmp5 = 2*r2*tmp;
	long double CBD = acos(tmp4/tmp5) * 2;
	// cout<<tmp4<<" "<<tmp5<<" "<<CBD<<endl;

	tmp4 = (r1*r1 + tmp*tmp - r2*r2);
	tmp5 = 2*r1*tmp;
	long double CAD = acos(tmp4/tmp5) * 2;
	// cout<<CAD<<endl;

	tmp4 = (CBD)*r2*r2;
	tmp5 = r2*r2*sin(CBD);
    tmp3 = (CAD)*r1*r1;
    tmp2 = r1*r1*sin(CAD);
	// cout<<tmp4<<" "<<tmp5<<" "<<tmp3<<" "<<tmp2<<endl;

	// pf("%.10Lf",(tmp4 - tmp5 + tmp3 - tmp2)/2.0);
    cout << (tmp4 - tmp5 + tmp3 - tmp2)/2<<endl;
	return 0;
}
