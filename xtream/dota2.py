from operator import itemgetter
from math import floor
N,M=map(int,raw_input().split(' '))
lst=[]
for i in range(1,N+1):
	tmp1,tmp2,tmp3=raw_input().split(',')
	score=map(int,tmp3.split(':'))
	score=(score[0]*100)/(score[0]+score[1])
	score=float(score/(1/float(i)))
	lst.append([tmp1,tmp2,score])
lst=sorted(lst, key=itemgetter(2),reverse=True)
inte=0
stre=0
agi=0
for i in range(M):
	if(lst[i][1]=='Intelligence'):
		inte=1
	elif(lst[i][1]=='Strength'):
		stre=1
	elif(lst[i][1]=='Agility'):
		agi=1
	print lst[i][0]
print ''
print 'This set of heroes:'
print 'Contains %.2f percentage of Intelligence' % (floor((inte*10000)/M)/100)
print 'Contains %.2f percentage of Strength' % (floor((stre*10000)/M)/100)
print 'Contains %.2f percentage of Agility' % (floor((agi*10000)/M)/100)
