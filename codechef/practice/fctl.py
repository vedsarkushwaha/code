T=int(raw_input())
for i in range(T):
	N=int(raw_input())
	sm=0
	num=1
	while(num<=N):
		num*=5
		#print num
		sm+=(N/num)
	print sm
