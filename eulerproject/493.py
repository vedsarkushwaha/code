from math import factorial as f
from fractions import Fraction

def ncr(n,r):
    return f(n)/(f(n-r)*(f(r)))


a = (Fraction(ncr(20,20),ncr(70,20)))*ncr(7,2)
b = (Fraction(ncr(30,20),ncr(70,20)))*ncr(7,3)
c = (Fraction(ncr(40,20),ncr(70,20)))*ncr(7,4)
d = (Fraction(ncr(50,20),ncr(70,20)))*ncr(7,5)
e = (Fraction(ncr(60,20),ncr(70,20)))*ncr(7,6)
f = (Fraction(ncr(70,20),ncr(70,20)))*ncr(7,7)

tmp = a*2+(b-a)*3+(c-b)*4+(d-c)*5+(e-d)*6+(f-e)*7
print float(tmp),tmp
