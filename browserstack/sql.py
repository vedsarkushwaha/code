from datetime import datetime
if __name__=="__main__":
	n,m=map(int,raw_input().split(', '))
	head=raw_input().split(',')
	data=[]
	for i in xrange(n):
		tmp=raw_input().split(',')
		for j in xrange(len(tmp)):
			tmp[j]=tmp[j].strip('"')
		tmp[0]=int(tmp[0])
		tmp[2]=datetime.strptime(tmp[2],"%Y-%m-%d %H:%M")
		tmp[3]=int(tmp[3])
		data.append(tmp)
	for pp in xrange(int(m)):
		ques=raw_input().split(' and Name = ')
		cnt=0;
		if(len(ques)==1):
			if(ques[0][0]=='I'):
				q1=int(ques[0].split(' > ')[1])
				for i in xrange(len(data)):
					if(data[i][0]>q1):
						cnt+=1;
			elif(ques[0][0]=='D'):
				q1=datetime.strptime((ques[0].split(' > ')[1]).strip('"'),"%Y-%m-%d %H:%M")
				for i in xrange(len(data)):
					if(data[i][2]>q1):
						cnt+=1;
			elif(ques[0][0]=='S'):
				q1=int(ques[0].split(' > ')[1])
				for i in xrange(len(data)):
					if(data[i][3]>q1):
						cnt+=1;
			elif(ques[0][0]=='N'):
				q1=ques[0].split(' = ')[1]
				for i in xrange(len(data)):
					if(data[i][1]>q1):
						cnt+=1;
		else:
			ques[1]=ques[1].strip('"')
			if(ques[0][0]=='I'):
				q1=int(ques[0].split(' > ')[1])
				for i in xrange(len(data)):
					if(data[i][0]>q1) and data[i][1]==ques[1]:
						cnt+=1;
			elif(ques[0][0]=='D'):
				q1=datetime.strptime((ques[0].split(' > ')[1]).strip('"'),"%Y-%m-%d %H:%M")
				for i in xrange(len(data)):
					if(data[i][2]>q1)  and data[i][1]==ques[1]:
						cnt+=1;
			elif(ques[0][0]=='S'):
				q1=int(ques[0].split(' > ')[1])
				for i in xrange(len(data)):
					if(data[i][3]>q1) and data[i][1]==ques[1]:
						cnt+=1;
		print cnt