#include<cstdio>
#include<cmath>
#include<iostream>
#define ll long long int
#define REP(i,n) for (ll i = 1; i <= n; i++)
ll const K=2;
ll MOD=1000003;
using namespace std;
void mul(ll A[][2], ll B[][2], ll C[][2])
{
C[0][0] = (A[0][0] * B[0][0]) % MOD;
C[0][0] = (C[0][0] + A[0][1] * B[1][0]) % MOD;

C[0][1] = (A[0][0] * B[0][1]) % MOD;
C[0][1] = (C[0][1] + A[0][1] * B[1][1]) % MOD;

C[1][0] = (A[1][0] * B[0][0]) % MOD;
C[1][0] = (C[1][0] + A[1][1] * B[1][0]) % MOD;

C[1][1] = (A[1][0] * B[0][1]) % MOD;
C[1][1] = (C[1][1] + A[1][1] * B[1][1]) % MOD;
}

void pow(ll A[][2], ll p, ll out[][2])
{
if (p == 1)
{
out[0][0] = A[0][0];
out[0][1] = A[0][1];
out[1][0] = A[1][0];
out[1][1] = A[1][1];
return;
}
if (p & 1)
{
ll B[2][2] = {{0}};
pow(A, p - 1, B);
mul(A, B, out);
}
else
{
ll X[2][2] = {{0}};
pow(A, p >> 1, X);
mul(X, X, out);
}
}

ll fibv(ll N)
{
if(N==-1)
return 0;
if(N==0)
return 1;
if(N==1)
return 1;
ll T[2][2] =
{
{1, 1},
{1, 0}
};

if (N == 1)
return 1;
ll F1[K+1];
F1[1] = 1;
F1[2] = 1;

ll RM[2][2] = {{0}};
pow(T, N-1, RM);

ll res = RM[0][1] % MOD;
res = (res + RM[0][0] ) % MOD;
return res;
}
int main()
{
ll t;
scanf("%llu",&t);
// t=10000;
ll n=1,m=1;
while(t--)
{
scanf("%llu%llu",&m,&n);
//n=1;
// n++;
// n=1000000000;
//cout<<(-1)%3;
ll ans=0;
if(m!=n)
{ans=(fibv(n+1)-fibv(m))%MOD;
if(ans<0)
ans=(MOD+ans)%MOD;
}
//cout<<ans<<endl;
else
ans=fibv(n-1);
printf("%lld\n",ans);
}
return 0;
}
