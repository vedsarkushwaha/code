from operator import mul
from fractions import Fraction

def calc(R,N,M):
	#if N=0 or M=0, then cooncatenate V or H
	#print N,M
	x=dp[N+M-1][M]
	#print x
	if M==0:
		for i in range(N):
			lst.append('H')
	elif(N==0):
		for i in range(M):
			lst.append('V')
	else:
		if R>x:
			lst.append('V')
			calc(R-x,N,M-1)
		else:
			lst.append('H')
			calc(R,N-1,M)

def getdp(x,y):
	lst=[]
	for i in range(x+1):
		tmp=[]
		for j in range(y+1):
			tmp.append(nCk(i,j))
		lst.append(tmp)
	return lst

def nCk(n,k):
	return int( reduce(mul, (Fraction(n-i, i+1) for i in range(k)), 1) )

dp=getdp(20,10)
T=int(raw_input())
for i in range(T):
	lst=[]
	N,M,K=map(int,raw_input().split(" "))
	#print dp
	#print N,M,K
	calc(K+1,N,M)
	pp=''.join(lst)
	print pp
