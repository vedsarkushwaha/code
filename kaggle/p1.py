from sklearn.ensemble import RandomForestClassifier
from numpy import genfromtxt, savetxt

def fun():
	dataset = genfromtxt(open('Data/train.csv','r'),delimiter=',',dtype='f8')[1:]
	target = [x[0] for x in dataset]
	train = [x[1:] for x in dataset]
	test = genfromtxt(open('Data/test.csv','r'),delimiter=',',dtype='f8')[1:]
	rf = RandomForestClassifier(n_estimators=100,n_jobs=4)
	rf.fit(train,target)
	predicted_probs = [[index + 1, x[1]] for index, x in enumerate(rf.predict_proba(test))]
	savetxt('Data/submission.csv', predicted_probs, delimiter=',', fmt='%d,%f', header='MoleculeId,PredictedProbability', comments = '')

if __name__ == "__main__":
	fun()
