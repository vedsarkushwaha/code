T=int(raw_input())
for i in range(T):
	lst=[]
	N=int(raw_input())
	lst=(map(int,raw_input().split(" ")))
	if(len(lst)%2==0):
		print "0"
	else:
		s=0
		for i in range(0,len(lst),2):
			s^=(lst[i])
		print s
