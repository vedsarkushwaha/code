import numpy as np
from datetime import datetime
from time import mktime
def read_inp():
	N=int(raw_input())
	train_ts=[]
	train_val=[]
	test_ts=[]
	for i in range(N):
		temp=raw_input().split("\t")
		if(temp[1][0]=="M"):
			test_ts.append(datetime.strptime(temp[0],'%m/%d/%Y %H:%M:%S'))
			test_ts[-1]=mktime(test_ts[-1].timetuple())
		else:
			train_ts.append(datetime.strptime(temp[0],'%m/%d/%Y %H:%M:%S'))
			train_ts[-1]=mktime(train_ts[-1].timetuple())
			train_val.append(float(temp[1]))
	return train_ts,train_val,test_ts

def calc_theta(x,y,theta):
	alpha=0.1
	m=230
	iteration=100
	print x.shape,theta.shape,y.shape
	error =	((x * theta) - y) #error is a sample_case:1 matrix
	print len(theta)
	for i in range(len(theta)):
		for j in range(iteration):
			theta[i] = theta[i]-(alpha/m)*(np.array(error)*np.array(x[:,i])).sum()
	return theta

def predict(theta,test_ts):
	return (test_ts * theta)

def set_feature(lst,feature):
	lst=[lst]
	for i in range(2,feature+1):
		lst.append([j**i for j in lst[0]])
	return lst

def feature_scale(mat):
	for i in mat:
		sz=len(i)
		mn=np.mean(i)
		mat[mat.index(i)]=[(j-mn)/sz for j in i]
	return mat

if __name__=="__main__":
	train_ts,train_val,test_ts=read_inp()
	feature=10
	#change theta to numpy matrix
	theta=(np.mat(np.ones(feature))).T
	train_ts=feature_scale(set_feature(train_ts,feature))
	test_ts=feature_scale(set_feature(test_ts,feature))
	#change train_ts, train_val into numpy matrix
	train_ts=(np.mat(train_ts)).T
	train_val=(np.mat(train_val)).T
	theta=calc_theta(train_ts,train_val,theta)
	#change test_ts into numpy matrix
	test_ts=(np.mat(test_ts)).T
	test_val=predict(theta,test_ts)
	for i in test_val:
		print i
