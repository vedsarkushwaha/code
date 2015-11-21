def fun(a,b,c,d,e,f,p):
	x=100000*a+10000*b+1000*c+d*100+e*10+f
	y=a**p+b**p+c**p+d**p+e**p+f**p
	if(x==y):
		return 1
	else:
		return 0

def digi(a,b,c,d,e,f):
	return 100000*a+10000*b+1000*c+d*100+e*10+f

if __name__=="__main__":
	tmp=0
	n=3
	for a in xrange(0,10):
		for b in xrange(0,10):
			for c in xrange(0,10):
				for d in xrange(0,10):
					for e in xrange(0,10):
						for f in xrange(0,10):
							if(a==0 and b==0 and c==0 and d==0 and e==0):
								continue
							if(fun(a,b,c,d,e,f,n)):
								tmp+=digi(a,b,c,d,e,f)
										# print a,b,c,d,e,f
	print tmp