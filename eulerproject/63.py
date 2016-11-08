cnt=0
for i in xrange(1,10):
    for j in xrange(1,30):
        tmp = i**j
        if len(str(tmp))==j:
            cnt+=1
    print i,cnt
print cnt
