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
int arr[1001];
int get_max() {
	var(int);
	ifr(i,1000,0) {
		if(arr[i]!=0) {
			return i;
		}
	}
}
int get_second_max() {
	var(int);
	tmp5=0;
	ifr(i,1000,0) {
		if(arr[i]!=0 && tmp5==1) {
			return i;
		}
		else if(arr[i]!=0) {
			tmp5=1;
		}
	}
	return 0;
}
int main() {
	var(int);
	sc("%d",&T);
	fr(i,1,T+1) {
		fr(j,0,1001)
			arr[j]=0;
		sc("%d",&N);
		fr(j,0,N) {
			sc("%d",&tmp);
			arr[tmp]+=1;
		}
		tmp1=0;
		while(1) {
			tmp4=get_second_max();
			tmp5=get_max();
			//pf("%d %d\n",tmp4,tmp5);
			tmp3=tmp5/2;
			if(tmp5%2) {
				fr(j,1,1001)
					arr[j]=arr[j+1];
				tmp1++;
				arr[1000]=0;
				tmp4--;
				tmp5--;				
			}
			if((max(tmp4,tmp3)+arr[tmp5]) < tmp5) {
				arr[tmp3]+=(arr[tmp5]*2);
				tmp1+=arr[tmp5];
				arr[tmp5]=0;
			}
			else {
				tmp1+=tmp5;
				break;
			}
		}
		pf("Case #%d: %d\n",i,tmp1);
	}
	return 0;
}