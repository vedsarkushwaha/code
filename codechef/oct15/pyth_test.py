lst=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71]

def div(num):
	tmp=num
	for i in xrange(2,int(tmp**0.5)+1):
		while(num%i==0):
			num=num/i
	return num

def checkHypo(num):

	for i in range(2,k):
		if k%i==0:


	tmp=num*2-1
	tmp1=int(tmp**0.5)
	if(tmp1*tmp1==tmp):
		return True
	else:
		return False

if __name__=="__main__":
	# generate pyth triplet
	for i in xrange(1,100):
		for j in xrange(1,100):
			for k in xrange(1,100):
				if i**2+j**2 == k**2:
					if(checkHypo(k)==False):
						print i,j,k
	print "Done"