from fractions import Fraction
T=int(raw_input())
while(T):
	T=T-1
	N,M=(raw_input()).split(" ")
	N=int(N)
	M=int(M)
	if(N%2==0):
		temp1=int(N/2)
	else:
		temp1=int(N/2)+1
	if(M%2==0):
		temp2=int(M/2)
	else:
		temp2=int(M/2)+1
	num=temp1*(M/2) + (N/2)*temp2
	dem=N*M
	if num==0:
		print "0/" +str(dem)
	elif num==dem:
		print "1/1"
	else:
		print Fraction(num,dem)
