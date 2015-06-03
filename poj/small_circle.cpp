#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
#define PI 3.1415926535
int main()
{
	int n,m,count=0;
	double r1,r2;
	cin>>n;
	while(n--)
	{
		count++;
		cin>>r1>>m;	
		r2=r1*sin(PI/m)/(1.0+sin(PI/m));
		printf("Scenario #%d:\n%.3f\n\n",count,r2);
		
	}
	return 0;
}
