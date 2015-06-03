#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MOD 10000007
 
int main()
{
 
long long int n , m, temp, i , j, prod;
long long int arr[50][50];
long long int sum;
scanf("%lld %lld" , &n , &m);
for(i = 1 ; i <= n ; i++)
{
for(j = 1 ; j <= m ; j++)
{
scanf("%lld" , &temp);
arr[i][j] = temp;
}
}
prod = 1;
for(i = 1 ; i <= m ; i++)
{	
sum = 0;
for(j = 1 ; j <= n ; j++)
{
sum += arr[j][i];
}
if(sum < 0)
sum = MOD + sum;
 
prod = (prod * sum) % MOD;
}
 
printf("%lld\n" , prod);
return 0;
}
