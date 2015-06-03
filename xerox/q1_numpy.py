from statistics import stdev,mean	
def read_inp(string):
	string=string.lstrip('[')
	string=string.rstrip(']')
	lst=string.split("),(")
	lst[0]=lst[0].lstrip('(')
	lst[-1]=lst[-1].rstrip(')')
	val=[]
	for i in lst:
		tmp1,tmp2=map(int,i.split(","))
		val.append([tmp1,tmp2])
	return val
	
def outlier(lst):
	tmp=[i[1] for i in lst]
	mn=mean(tmp)
	std=stdev(tmp)
	print(mn,std)
	res=[]
	for i in lst:
		if abs(i[1]-mn)>std:
			res.append(i)
	return res

def get_ind(lst1):
	l=len(lst1)
	if l==0:
		print("[]")
	elif l==1:
		print("[("+lst1[0]+","+lst1[0]+")]")
	i=0
	#print(lst1)
	ind=[]
	flag=0
	while(i<l-1):
		if(lst1[i][0]+1==lst1[i+1][0]):
			tmp=lst1[i][0]
			while i+1<l and (lst1[i][0]+1==lst1[i+1][0]):
				i+=1
				#print(i)
				continue
			ind.append([tmp,lst1[i][0]])
	if i<l-1:
		ind.append([i,i])
	#print#
	print("[")
	for i in ind:
		if ind.index(i)<len(ind):
			print("("+str(i[0])+","+str(i[1])+"),")
		
	print(ind)
	#return ind

if __name__=="__main__":
	string=input()
	lst=read_inp(string)
	lst1=outlier(lst)
	#ind_outlier=get_ind(lst1)
	get_ind(lst1)
	#print(lst1)
