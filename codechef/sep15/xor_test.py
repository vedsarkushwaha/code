def fun(x):
	tmp=0
	for i in xrange(1,x+1):
		tmp=tmp^i
	return tmp


for i in xrange(1,10):
	print fun(i)