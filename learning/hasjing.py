lst={}
def fun(N,md):
	i=0
	while(1):
		tmp=(N**i)%md
		if tmp in lst:
			print len(lst)
			return
		else:
			lst[tmp]=1
			i+=1

if __name__=="__main__":
	fun(7,103)