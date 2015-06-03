#include<bits/stdc++.h>
using namespace std;
int main(){int T,N,v,i,j,ar[110][110]={0};cin>>T;while(T--){cin>>N;v=0;for(i=1;i<=N;i++)for(j=1;j<=i;j++){cin>>ar[i][j];ar[i][j]+=max(ar[i-1][j],ar[i-1][j-1]);v=max(v,ar[i][j]);}cout<<v<<endl;}return 0;}
