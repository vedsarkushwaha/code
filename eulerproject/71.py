from fractions import Fraction
limit = 1000000

lst = []

if __name__=="__main__":
    ts = Fraction(3,7)
    for i in range(2,limit+1):
        for j in range(i/2-10,i/2+10):
            lst.append(Fraction(j,i))
    lst.sort()
    i=lst.index(ts)
    print i
    print lst[i-1],lst[i],lst[i+1]
