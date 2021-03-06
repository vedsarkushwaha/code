#include<bits/stdc++.h>
using namespace std;
char arr[1001][1001];
int dp[1001][1001];
int n,m,k,ik,x,y;
int p[1000005]={0};
int ans=0;
void dfs(int i,int j)
{
    if(i==0||j==0||i==n+1||j==m+1)
        return;
    if(arr[i][j]=='*')
    {
        ans++;
        return;
    }
    if(dp[i][j]!=0)
        return;
    dp[i][j]=ik;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
    return;
}
int main()
{

    cin>>n>>m>>k;
    for(ik=1;ik<=n;ik++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[ik][j];
        }
    }
    for(ik=1;ik<=k;ik++)
    {
        cin>>x>>y;
        ans=0;
        if(!dp[x][y])
            dfs(x,y);
        else
        ans=p[dp[x][y]];
        p[ik]=ans;
        cout<<ans<<endl;
    }

}