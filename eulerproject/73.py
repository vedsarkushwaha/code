from fractions import Fraction
limit = 12000

lst = []

if __name__=="__main__":
    ot = Fraction(1,2)
    oh = Fraction(1,3)
    for i in range(1,limit+1):
        print i
        for j in range(1,i):
            if(Fraction(j,i)>=ot):
                break;
            if(Fraction(j,i)<=oh):
                continue;
            lst.append(Fraction(j,i))
    print "Array Formed"
    lst.sort()
    print "Array Sorted"
    i=lst.index(ot)
    j=lst.index(oh)
    print i,j
    while(lst[j]==ts):
        j+=1
    print i-j
