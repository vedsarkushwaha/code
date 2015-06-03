from math import factorial as fact
from fractions import Fraction
def fun(x,i):
	sm=0;
	for j in range(i):
		tmp=Fraction((x**(2*j+1)),fact(2*j+1))
		sm+=((-1)**j)*tmp
	return sm
	
if __name__=="__main__":
	while(1):
		print fun(float(raw_input()),int(raw_input()))
