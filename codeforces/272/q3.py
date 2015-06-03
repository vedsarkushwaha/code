a,b=map(int,raw_input().split(' '))
s=0
for k in xrange(1,a+1):
	t=b-1
	s+=(k*b*t)+(t*(t+1))/2
	s=s%1000000007
print s
