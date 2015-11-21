from fractions import gcd

for n in xrange(1,100):

	total=0

	for i in xrange(1,n+1):
		total+=(n/gcd(i,n))

	print total,n