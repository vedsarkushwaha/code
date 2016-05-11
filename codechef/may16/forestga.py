trees=[]

def getWood(month, L, W):
	tmp=0
	for i in range(len(trees)):
		if((trees[i][0] + trees[i][1]*month) >= L):
			tmp+=(trees[i][0] + trees[i][1]*month)
			if(tmp>W):
				return 1
			# pf("%lld:%lld:%lld\n",i,month,trees[i].first + trees[i].second*month);

	assert(tmp<=W and tmp>=0)
	if(tmp==W):
		return 0
	else:
		return -1
 
if __name__=="__main__":
	N,W,L=map(int, raw_input().split(' '))
	for i in range(N):
		tmp1,tmp2=map(int,raw_input().split(' '))
		trees.append([tmp1,tmp2])

	low=0
	high=1000000000000000000
 
	prevAns=high;

	assert(getWood(high,L,W)>=0)
	#binary search
	while(high>=low):
		mid=(high+low)/2
		tmp5 = getWood(mid,L,W)
		#pf("%lld %lld %lld %lld %lld\n",low,mid,high,W,tmp5);
		if(0==tmp5):
			print mid
			exit(0)
		elif(low==mid):
			break
		elif(tmp5>0):
			prevAns=mid
			assert(getWood(prevAns,L,W)>0)
			high=mid
		elif(tmp5<0):
			low=mid

	if(getWood(mid,L,W)>=0):
		print mid
	else:
		# assert(mid+1==prevAns);
		mid+=1
		while(getWood(mid,L,W)<0):
			mid+=1
			assert(mid<=prevAns);
		print mid
	exit(0)