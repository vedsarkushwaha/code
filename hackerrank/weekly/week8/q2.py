
from fractions import gcd
T=int(raw_input())
def fun(lst):
	nlst=[]
	nlst.append(lst[0])
	leng=len(lst)
	for i in range(1,leng):
		nlst.append((lst[i]*lst[i-1])/gcd(lst[i],lst[i-1]))
	nlst.append(lst[-1])
	return nlst
for i in range(T):
	N=int(raw_input())
	lst=[]
	lst.extend(map(int,raw_input().split(" ")))
	nlst=fun(lst)
	for i in nlst:
		print i,
	print
