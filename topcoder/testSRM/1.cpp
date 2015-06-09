#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

class PrivateD2party {
    public:
    	int getsz(vector <int> a) {
    		int i,j,k,tmp5;
    		int lst[a.size()];
    		int arr[a.size()];
    		fr(i,0,a.size()) {
                arr[i]=0;
                lst[i]=0;
            }
    		fr(i,0,a.size()) {
    			if(a[i]==i) {
    				lst[i]=1;
                    tmp5++;
    				a[i]=-1;
    			}
                else arr[a[i]]++;
    		}
    		int com[a.size()];
    		fr(i,0,a.size()) com[i]=0;
    		fr(i,0,a.size()) {
                if(lst[i]==1) continue;
    			fr(j,0,a.size()) {
    				if(arr[j]==i) {
    					if(com[a[j]]!=1)
    						com[j]=1;
    				}
    			}
    		}
    		int cnt=0;
    		fr(i,0,a.size()) if(com[i]==1) cnt++;
    		return cnt+tmp5;
    	}
};