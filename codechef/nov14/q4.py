def fun(N,M):
	sm=1
	for i in xrange(1,N+1):
		sm*=pow(i,i,M)
	return sm

if __name__=="__main__":
	n,r,m=map(int,raw_input().split(' '))
	print fun(n,m)/(fun(n-r,m)*fun(r,m))