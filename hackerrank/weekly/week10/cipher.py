N,K=map(int,raw_input().split(" "))
inp_str=map(int,list(raw_input().rstrip("\n")))
lst=[inp_str[0]]
tmp=0
i=0
while(len(lst)<=K-1):
	tmp=lst[i] ^ tmp
	tmp1=tmp^inp_str[i+1]
	i+=1
	lst.append(tmp1)

#print lst
while(len(lst)!=N):
	tmp=tmp^lst[len(lst)-K]^lst[i]
	tmp1=tmp^inp_str[i+1]
	i+=1
	lst.append(tmp1)
print ''.join(map(str,lst))