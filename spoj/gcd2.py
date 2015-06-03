from fractions import gcd
T=int(input())
for i in range(T):
	a,b=map(int,input().split(' '))
	print(gcd(a,b))
