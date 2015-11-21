from bisect import bisect_left
pr=[]
lst1=[]

def b_s(x, lo=0, hi=None):
	hi = hi if hi is not None else len(pr) # hi defaults to len(a)   
	pos = bisect_left(pr,x,lo,hi)          # find insertion position
	return (pos if pos != hi and pr[pos] == x else -1)

def fact(val):
	return [[i, val / i] for i in range(1, int(val**0.5)+1) if val % i == 0]

def f(val):
	tmp=fact(val)
	while(1):
		fag=0
		for i  in tmp:
			print i
		for i in tmp:
			if (b_s(i[0],0)!=-1) and chk(i[0])==0:
				tmp.pop(tmp.index(i))
			elif b_s(i[1],0)!=-1 and chk(i[0])==0:
				tmp.pop(tmp.index(i))
			else:
				if (b_s(i[0],0)==-1) and chk(i[0])==0:
					tmp1=fact(i[0])
					tmp[tmp.index(i)].pop(0)
					tmp[tmp.index(i)].extend(tmp1)
					fag=1
					print i
				if (b_s(i[1],0)==-1) and chk(i[1])==0:
					tmp1=fact(i[1])
					tmp[tmp.index(i)].pop(1)
					tmp[tmp.index(i)].extend(tmp1)
					fag=1
		if(fag==0):
			break

def sp(n):
	size = n//2
	sieve = [1]*size
	limit = int(n**0.5)
	for i in range(1,limit):
		if sieve[i]:
			val = 2*i+1
			tmp = ((size-1) - i)//val 
			sieve[i+val::val] = [0]*tmp
	return [1]+[2] + [i*2+1 for i, v in enumerate(sieve) if v and i>0]

def chk(N):
	#check N is in combi of lst or not
	#print N
	tmp=map(int,list(str(N)))
	for i in tmp:
		if lst1[i]!=1:
			return 0
	return 1

if __name__=="__main__":
	pr=sp(1000001)
	T=int(raw_input())
	for ii in range(T):
		lst1=map(int,raw_input().split(' '))
		N=int(raw_input())
		lst=f(N)
		while(1):
			lst=f(N)
			for i in lst:
				print i
