if __name__=="__main__":
    # a,b=map(int,raw_input().split(' '))
    aS=2
    aE=10
    bS=10
    bE=20
    sqrMap={}
    for i in xrange(aS,aE+1):
        sqrMap[i**2]=1
    cnt=0
    for i in xrange(aS,aE+1):
        print i,
        if i in sqrMap:
            if bE/2>=bS:
                cnt+=((bE-bS + 1)-(bE/2 - bS + 1))
                print ((bE-bS + 1)-(bE/2 - bS + 1))
        else:
            cnt+=(bE-bS + 1)
            print (bE-bS+1)
    print cnt