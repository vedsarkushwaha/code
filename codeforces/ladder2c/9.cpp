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

int diff(char a,char b) {
	var(int);
	tmp=abs(a-b);
	if(tmp>13) return 26-tmp;
	else return tmp;
}

int main() {
	var(int);
	int n,p,mid;
	int left=-1,right=-1;
	string str;
	sc("%d %d\n",&n,&p);
	p-=1;
	cin>>str;
	mid=str.length()/2;
	i=0;
	tmp=0;
	while(i<mid) {
		if(str[i]!=str[str.length()-i-1]) {
			if(left==-1) left=i;
			right=i;
		}
		tmp+=diff(str[i],str[str.length()-i-1]);
		i++;
	}
	pf("%d %d %d %d\n",tmp,left,right,mid);
	if(p>=mid) {
		p=mid-(p-mid);
		if(n%2==0) p-=1;
	}
	if(left==-1) pf("0");
	else {
		if(p>=right) {
			tmp+=(p-left);
			pf("right");
		}
		else if(p<=left) {
			tmp+=(right-p);
			pf("left");
		}
		else {
			pf("ib");
			if(p-left<right-p) {
				tmp+=((p-left)+(p-left)+(right-p));
				pf("left end is smaller %d %d\n",p-left,right-p);
			}
			else {
				tmp+=((right-p)+(right-p)+(p-left));
				pf("right end is smaller %d %d\n",right-p,p-left);
			}
		}
		pf("%d",tmp);
	}
	return 0;
}