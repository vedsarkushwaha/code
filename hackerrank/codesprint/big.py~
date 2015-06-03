def chk(lst):
	k=lst[0]
	for i in lst:
		if i!=k:
			return 0
	return 1

T=int(raw_input())
for i in range(T):
	st=raw_input().rstrip('\n')
	lst=list(st)
	l=len(lst)
	flag=0
	for i in range(l-1,0,-1):
		if(lst[i]>lst[i-1]):
			flag=1
			tmp=lst[i-1]
			lst.pop(i-1)
			for i in range(l-2,-1,-1):
				if tmp<lst[i]:
					lst.insert(i+1,tmp)
					break
			break
	if flag==0:
		print "no answer"
	else:
		print ''.join(lst)
