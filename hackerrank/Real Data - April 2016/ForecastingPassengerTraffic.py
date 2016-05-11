import numpy as np

N = int(raw_input())
x = []
y = []
for i in xrange(N):
	monNumber, population = raw_input().rstrip('\n').split()
	x.append(i)
	y.append(int(population))

# mn = numpy.mean(y)
# for i in range(12):
# 	print mn

# for i in range(12):
# 	print y[i]

# z = np.polyfit(x, y, 2)
# p = np.poly1d(z)

for i in range(1,13):
	print y[-i]