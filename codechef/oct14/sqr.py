N=int(raw_input())
lst=[]
for i in range(N):
	lst.append(raw_input())
for i in range(N):
	tmp=lst[i].split(' ')[1]+" "+lst[i].split(' ')[0]
	if tmp in lst:
		print 
