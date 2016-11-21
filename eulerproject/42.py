if __name__=="__main__":
    words = raw_input().split('","');
    words[0] = words[0][1:]
    words[-1]=words[-1][0:-1]
    # print words
    sm = {}
    total=0
    for i in xrange(1,50):
        total=total+i
        sm[total]=1

    for i in sm:
        print i

    k=0
    for w in words:
        total = sum(j-64 for j in map(ord, (i for i in w)))
        if total in sm:
            print w
            k=k+1
    print k
