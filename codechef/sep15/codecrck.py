from decimal import *
from fractions import Fraction
getcontext().prec=15
x=Fraction(2**0.5)
y=Fraction(3**0.5)
mr=[x-x*y, x+x*y, x+x*y, x*y-x]
ls=[(1-y)/(8*x), (1+y)/(8*x), (1+y)/(8*x), (y-1)/(8*x)]
un=map(Fraction,[1,0,0,1])

def matmul(x,y):
	z=[x[0]*y[0]+x[1]*y[2], x[0]*y[1]+x[1]*y[3], x[2]*y[0]+x[3]*y[2], x[2]*y[1]+x[3]*y[3]]
	return z

def power(x, y):
	if(y==0):
		return un;
	if(y==1):
		return x
	temp=power(x, y/2)
	temp=matmul(temp,temp)
	if(y%2==0):
		return temp;
	else:
		return matmul(x,temp);

def fun(I,K,A,B):
	global ls,mr
	tmp1,tmp2=A,B
	if(K<I):
		ls=power(ls,I-K);
		tmp1=ls[0]*A+ls[1]*B;
		tmp2=ls[2]*A+ls[3]*B;
	elif(K>I):
		mr=power(mr,K-I);
		tmp1=mr[0]*A+mr[1]*B;
		tmp2=mr[2]*A+mr[3]*B;
	return tmp1,tmp2

if __name__=="__main__":
	i,k,s=map(int,raw_input().split())
	val1,val2=map(Fraction,raw_input().split())
	# print type(val1),val2
	val1,val2=fun(i,k,val1,val2);
	# print val1,val2
	val=val1+val2;
	# while(s>0):
	# 	val=val/2
	# 	s-=1
	# while(s<0):
	# 	val=val*2
	# 	s+=1
	pt=Fraction(pow(2,s))
	if(s>0):
		val=val/pt
	elif(s<0):
		val=val*pt
	print round(val,3)
	exit(0)