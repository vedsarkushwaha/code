a,b = map(int, raw_input().split(' '))

dl = len(list(bin(a))[2:])
dr = len(list(bin(b))[2:])

tmp=0
for i in xrange(dl+1,dr):
	tmp+=(i-1)

# print tmp

for i in xrange(1,dl):
	lst=[1]*dl
	lst[i]=0
	if(int((''.join(map(str,lst))),2)>=a and int((''.join(map(str,lst))),2)<=b):
		tmp+=1

# print tmp

if(dl!=dr):
	for i in xrange(1,dr):
		lst=[1]*dr
		lst[i]=0
		if(int((''.join(map(str,lst))),2)>=a and int((''.join(map(str,lst))),2)<=b):
			tmp+=1

print tmp