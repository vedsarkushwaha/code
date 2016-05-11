from statistics import pstdev

m=4
lhs = round(pstdev([1,2,3]),m)

# rng = [0.00001 * x for x in range(99999,200000)]
rng = [0.01 * x for x in range(1,200000)]
for i in rng:
	print(lhs,round(pstdev([1,2,3,i]),m),i)
	if lhs==round(pstdev([1,2,3,i]),m):
		print(i)
		break