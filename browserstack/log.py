import operator
if __name__=="__main__":
	pdf={}
	lst=[]
	while(1):
		inp=raw_input()
		if inp=="EOF":
			break
		inp=inp.split('HTTP/1.1" ')
		inp=inp[1].split(' ')
		#if(inp[1].isdigit()==True):
		inp=int(inp[0])
		lst.append(inp)
		#else:
		#	inp=''
		for i in xrange(len(lst)):
			tmp=lst[i]
			for j in xrange(len(pdf)):
				
		if inp in pdf:
			pdf[inp]+=1
		else:
			pdf[inp]=1
	#sl=sorted(pdf.iteritems(),key=operator.itemgetter(1),reverse=True)
	for i in sl:
		print i[0],i[1]
	print " 1"