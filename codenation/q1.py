from math import ceil
md=1000000000
lst={}
def fun(N):
  if N==0 or N==1 or N==2:
    return 1
  elif N==3 or N==4:
    return 3
  elif N==5 or N==6:
    return 15
  elif N==7 or N==8 or N==9 or N==10:
    return 105
  else:
    if N in lst:
      return lst[N]
    else:
      tmp=(pow(2,int(ceil(float(N)/4)),md)*fun(ceil(float(N)/5))*fun(ceil(float(N)/10)))%md
      #print pow(2,int(ceil(float(N)/4)),int(1000000000)),fun(ceil(float(N)/5)),fun(ceil(float(N)/10))
      lst[N]=tmp
      return tmp
    
T=int(raw_input())
for kkk in xrange(T):
  N=int(raw_input())
  tmp=fun(N)
  #print tmp
  tt=0
  for x in xrange(1,6):
    for y in xrange(1,6):
      if x==y:
	continue
      tt=max(tt,pow(x*tmp,y*tmp,md))
  print tt