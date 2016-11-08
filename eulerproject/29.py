if __name__=="__main__":
    N = 100000
    unique = {}
    for i in xrange(2,N+1):
        for j in xrange(2,N+1):
            tmp = i**j;
            if tmp not in unique:
                unique[tmp]=1;
            else:
                unique[tmp]+=1;
    print len(unique)
