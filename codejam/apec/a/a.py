def cycle(n):
	if n==0:
		return 9
	else:
		return n-1

T=int(raw_input())
num=['1111110','0110000','1101101','1111001','0110011','1011011','1011111','1110000','1111111','1111011']
def rev_cycle(n):
	if n==9:
		return 0
	else:
		return n+1
for ii in range(1,T+1):
	N=raw_input().split(' ')
	disp=N[1:]
	N=int(N[0])
	all_corr=0
	for j in range(N):
		all_corr=(all_corr | int(disp[j],2))
	poss_val=[]
	for j in range(N):
		#calc off bits in disp[j]
		off_bits=int(disp[j],2) ^ all_corr
		tmp=[]
		for i in range(10):
			if (int(num[i],2) & off_bits)==0 and (int(disp[j],2) & int(num[i],2))==int(disp[j],2):
				tmp.append(i)
		poss_val.append(tmp)
	print poss_val
	print bin(all_corr).replace('0b','').zfill(7)
	cnt=0
	for j in poss_val[0]:
		flag=0
		l=j
		for pp in poss_val[1:]:
			l=cycle(l)
			#print l,pp
			if l not in pp:
				flag=1
				break
		if flag==0:
			ans=cycle(l)
			cnt+=1
	ambi_bits=0
	tmp=ans
	for i in range(N):
		ambi_bits=(ambi_bits | (tmp ^ 8))
		tmp=rev_cycle(tmp)
	ambi_bits=(ambi_bits & (~all_corr))
	if cnt!=1 or (ans & ambi_bits)!=0:
		print "Case #"+str(ii)+": ERROR!"
	else:
		print "Case #"+str(ii)+": "+str(bin(int(num[ans & all_corr],2) & all_corr).replace('0b','').zfill(7))
	#print cnt
