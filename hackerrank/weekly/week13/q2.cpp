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
	var(int);
	int arr[26]={0},arr1[26]={0};
	string str1;
	sc("%d",&T);
	while(T--) {
		cin>>str1;
		tmp5=0;
		fr(tmp2,0,str1.length()-1) {
			fr(i,1,str1.length()-tmp2) {
				tmp4=0;
				fr(k,0,26)
					arr[k]=0;
				fr(k,tmp2,i+tmp2) {
					arr[str1[k]-'a']+=1;
					//pf("%c",str1[k]);
				}
				//pf("\n");
				fr(j,tmp2+1,str1.length()-i+1) {
					tmp3=0;
					fr(k,0,26)
						arr1[k]=0;
					fr(k,j,j+i) {
						arr1[str1[k]-'a']+=1;
						//pf("%c",str1[k]);
					}
					//chk
					fr(k,j,j+i) {
						if(arr[str1[k]-'a']!=arr1[str1[k]-'a']) {
							tmp3=1;
							break;
						}
					}
					//pf("\n");
					if(tmp3==0) {
						//pf("d\n");
						tmp4++;
					}
				}
				//pf("\n");
				tmp5+=tmp4;
			}
		}
		pf("%d\n",tmp5);
	}
	return 0;
}
