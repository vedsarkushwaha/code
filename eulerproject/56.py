sm=0


for a in xrange(1,100):
    for b in xrange(1,100):
        tmp = sum(map(int,str(a**b)))
        if tmp>sm:
            sm=tmp

print sm
