p=0
T=int(raw_input())
for i in range(T):
	N=int(raw_input())
	a=[]
	for i in range(N):
		a.append(map(int,raw_input().split(' ')))
		if(i):
			(j==0)?(a[i][j]+=a[i-1][j]):((a[i-1][j]>a[i-1][j-1])?(a[i][j]+=a[i-1][j]):(a[i][j]+=a[i-1][j-1]))
			p=max(p,a[i][j])
print p
