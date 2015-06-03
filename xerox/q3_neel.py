#import numpy


def model(x, period, predict, alpha , beta , gamma):

 	val = x[:]
  
  	sum_period = sum(val[0:period])
  	sum_2_period = sum(val[period:2 * period]) 

	a = [ sum_period/ float(period)]
	b = [(sum_2_period - sum_period) / (period ** 2)]
	s = [val[i] - a[0] for i in range(period)]
	y = [a[0] + b[0] + s[0]]
	rmse = 0
 
	for i in range(len(val) + predict):
 
		if i == len(val):
			val.append(a[-1] + b[-1] + s[-period])
 
		a.append(alpha * (val[i] - s[i]) + (1 - alpha) * (a[i] + b[i]))
		b.append(beta * (a[i + 1] - a[i]) + (1 - beta) * b[i])
		s.append(gamma * (val[i] - a[i] - b[i]) + (1 - gamma) * s[i])
		y.append(a[i + 1] + b[i + 1] + s[i + 1])
 
	rmse = (sum([(i - j) ** 2 for i, j in zip(val[:-predict], y[:-predict - 1])])**.5 / len(val[:-predict]))
 
	return val[-predict:], rmse


def frange(x,y,gap):
	return [x * gap for x in range(x, y)]

def grid_search(y):

	min_err = 999999999999
	ma = mb = mc = -1
	for alpha in frange(0,11,.1):
		for beta in frange(0,11,.1):
			for gamma in frange(0,11,.1):


				#err = holtwinters(y,alpha, beta, gamma, 7, False)

				(res, err) = model(y, 7, 1, alpha, beta, gamma)

				if(err < min_err):
					min_err = err
					(ma, mb, mc) = (alpha, beta, gamma)

	(res, err) = model(y, 7, 35, ma, mb+.05, mc)
	#print ma, mb, mc
	#print res

	k = 0

	for j in range(1,6):
		for i in range(1,8):
			print str(i) + ',' + str(int(res[k] + 0))
			k+=1
			


t = int(raw_input())

y = []
for i in range(t):
	(a,b) = map(int, raw_input().split(','))
	y.append(b)
#print y
#y = [2,4,6,2,8,9,8,2,4,6,2,8,9,8,2,4,6,2,8,9,8,2,4,6,2,8,9,10]
print 35
grid_search(y)
