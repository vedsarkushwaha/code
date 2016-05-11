def chkPrime(num):
	for i in xrange(2,int(num**0.5)+1):
		if(num%i==0):
			return False, i
	return True, -1

def chkJamCoin(i):
	lst=[]
	if(i%2==0):
		return False, []
	for j in xrange(2,11):
		num = int(bin(i)[2:],j)
		a,b = chkPrime(num)
		if(a==True):
			return False, []
		else:
			lst.append(b)
	return True, lst

if __name__=="__main__":
	T=int(raw_input())
	for k in xrange(T):
		N,J=map(int,raw_input().split())
		# ll=int("1000000000000001",2)
		# ul=int("1111111111111111",2)
		ll = 2**(N-1)+1
		ul = 2**(N)-1
		cnt=0
		for i in xrange(ll,ul+1):
			a,b=chkJamCoin(i)
			if(a==True):
				print bin(i)[2:],
				for j in b:
					print j,
				print
				cnt+=1
				if(cnt==J):
					break
