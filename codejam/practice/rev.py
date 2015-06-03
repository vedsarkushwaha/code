N=int(raw_input())
for i in xrange(1,N+1):
	lst=raw_input().split(' ')
	lst.reverse()
	print "Case #"+str(i)+': '+' '.join(lst)
