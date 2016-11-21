
cnt=0
if __name__=="__main__":
    for i in range(1,1000001):
        if str(i)==str(i)[::-1] and bin(i)[2:]==bin(i)[2:][::-1]:
            cnt+=i
            print i
    print cnt
