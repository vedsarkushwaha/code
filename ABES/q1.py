def chk(n):
	if n==1 or n==0:
		return '0'
	for i in range(2,n-1):
		if n%i==0:
			return '0'
	return '1'
	
try:
	n=int(raw_input())

	num=''
	for i in range(n):
		tmp=map(int,list(raw_input()))
		num+=chk(sum(tmp))
		num1=int(num,2)

	print num1
except:
	pass