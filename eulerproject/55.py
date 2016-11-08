

if __name__=="__main__":
    lych=0
    for i in xrange(1,10001):
        iteration=0
        tmp = i
        while(True):
            print tmp
            iteration+=1
            if iteration>50:
                lych+=1
                # print i
                break
            tmp+=int(str(tmp)[::-1])
            if tmp==int(str(tmp)[::-1]):
                # print i
                break
    print lych
