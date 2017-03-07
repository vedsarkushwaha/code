from fractions import Fraction as F

def getVal(i):
    if((i+1)%3==0):
        return ((i+1)/3)*2
    else:
        return 1

def fun(i):
    if i==99:
        return F(1,getVal(i))
    else:
        return F(1,getVal(i)+fun(i+1))

tmp = 2+fun(1)
print tmp
print sum(map(int,str(tmp.numerator)))
