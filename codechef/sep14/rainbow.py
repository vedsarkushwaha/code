from math import factorial as fact

def combi(d):
	s=1
	for i in range(1,7):
		s*=(i+d)
	return s/(fact(6))

N=int(raw_input())
if N<13:
	print "0"
else:
	d=(N-13)/2
	c=combi(d)
	print c%(1000000007)
