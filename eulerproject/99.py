

if __name__=="__main__":
    lst=[]
    mxExp=0
    mnExp=9111111
    for i in xrange(1,1001):
        num,exp = map(int,raw_input().split(","))
        mxExp = max(mxExp, exp)
        mnExp = min(mnExp, exp)
        lst.append([num,exp])
    # print lst
    print mxExp, mnExp

    mxNum = 0
    cnt=0
    for i in lst:
        print i
        cnt+=1
        num,exp = i[0],i[1]
        num = num ** (exp-mnExp+1)
        if num>mxNum:
            print "Found Bigger Number"
            print cnt
            mxNum = num
        # print cnt
    # print mxNum
