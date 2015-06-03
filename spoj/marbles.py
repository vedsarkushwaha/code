from math import factorial as fac
def calc(n,k):
	return fac(n)/(fac(n-k)*fac(k))
	
if __name__=="__main__":
	T=int(raw_input())
	for i in xrange(T):
		t1,t2=map(int,raw_input().split(' '))
		print calc(t1-1,t2-1)
