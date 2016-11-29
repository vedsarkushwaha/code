N=1000000000000
# N=100000000
if __name__=="__main__":
    n = N;
    while(1):
        tmp = n*(n-1)
        tmp1=tmp/2
        tmp0=tmp1
        tmp2=int(tmp1**0.5)
        if tmp1%tmp2==0 and tmp1%(tmp2+1)==0:
            tmp1=tmp1/tmp2
            tmp1=tmp1/(tmp2+1)
            if(1 == tmp1):
                print tmp0,tmp
                break
        n=n+1
    print int(tmp0**0.5),int(tmp0**0.5)+1
    print int(tmp**0.5),int(tmp**0.5)+1
