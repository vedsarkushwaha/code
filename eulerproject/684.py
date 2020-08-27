md=1000000007

def sn(n):
  ans = 0

  nineCount = n//9
  lastDigit = n - nineCount*9

  print(nineCount)
  temp = pow(10, nineCount, md)
  ans = ((lastDigit * temp)%md + temp - 1) % md

  return ans

def main():
    ans = 0

    i=2
    j=90
    faba=0; fabb=1
    while(i<=90):
        fabc=faba+fabb
        faba=fabb
        fabb=fabc

        ans = (ans + ((sn(fabc) * j) % md)) % md

        print(i, fabc, ans)

        i = i+1;
        j = j-1;
    print(ans)

if __name__=="__main__":
    main()
