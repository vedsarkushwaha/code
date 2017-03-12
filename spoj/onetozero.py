def chk(num):
    if sum([int(x)>1 for x in str(num)]) > 0:
        return False
    else:
        return True

if __name__=="__main__":
    T=int(raw_input())
    for t in xrange(T):
        num = int(raw_input())
        if chk(num):
            print num
        else:
            i=2**len(str(num))
            while(True):
                tmp = int(bin(i)[2:])
                if tmp % num == 0:
                    break
                i+=1
            print tmp
