from fractions import Fraction

if __name__=="__main__":
    ans=Fraction(1,2);
    cnt=0
    for i in xrange(1,1001):
        tmp = 1+ans
        if len(str(tmp.numerator))>len(str(tmp.denominator)):
            cnt+=1
        ans = Fraction(1,2+ans)
    print cnt
