if __name__=="__main__":

	n,k,x=map(int,raw_input().split())
	mx=0
	mor=0
	lst=map(int,raw_input().split())

	pre=[p for p in lst]
	suf=[p for p in lst]

	for i in range(1,len(lst)):
		pre[i]=pre[i-1]|pre[i]
		suf[len(lst)-i-1]=suf[len(lst)-i]|suf[len(lst)-i-1]

	if len(lst)==1:
		print lst[0]*(x**k)
		exit(0)
	
	mx=0
	for i in range(len(lst)):
		if i==0:
			tmp=max(mx, (lst[i]*(x**k))|suf[i+1])
		elif i==len(lst)-1:
			tmp=max(mx, (lst[i]*(x**k))|pre[i-1])
		else:
			tmp=max(mx, (lst[i]*(x**k))|pre[i-1]|suf[i+1])

		mx=max(mx,tmp)
	# print
	print mx