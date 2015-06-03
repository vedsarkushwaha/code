import sys

def summ_cube(x):
	return pow(((x*(x+1))/2),2)

def summ_quad(n):
	return (n*(2*n+1)*(n+1)*(3*n*n+3*n-1))/30

def rec(N,i):
	if i==1:
		return 0
	else:
		p2=N*(summ_cube(N)-summ_cube(N/2))
		p3=(summ_quad(N)-summ_quad(N/2))
		#sys.stdout.write(str(N) + ' ' + str(i))
		return rec(N,i/2) + (p2-p3)

T=int(raw_input())
for j in range(T):
	#N,M=map(int,raw_input().split(" "))
	N=int(raw_input())
	#p1=N*summ_cube(N) - rec(N,N)
	print rec(N,N)
