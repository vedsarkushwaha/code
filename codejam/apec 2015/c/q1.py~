import sys

sys.setrecursionlimit(15000)

T=int(raw_input())
for iii in range(T):
	N=int(raw_input())
	mat=[[0 for i in range(N+2)] for j in range(N+2)]

	def chk_zero(i,j):
		for k in [-1,0,1]:
			for l in [-1,0,1]:
				if k==0 and l==0:
					continue
				else:
					if mat[i+k][j+l]=='*':
						return 0
		return 1
		#if . -> 0 then return 1

	def open_negh(i,j):
		for k in [-1,0,1]:
			for l in [-1,0,1]:
				if k==0 and l==0:
					continue
				if mat[i+k][j+l]=='.' and chk_zero(i+k,j+l):
					#print i+k,j+l
					mat[i+k][j+l]='0'
					open_negh(i+k,j+l)
				elif mat[i+k][j+l]=='.':
					mat[i+k][j+l]='1'
	def printmat():
		for i in mat:
			print i


	for i in range(1,N+1):
		mat[i][1:N+1]=raw_input()
	tmp=0
	while(1):
		flag=0
		for i in range(1,N+1):
			for j in range(1,N+1):
				if mat[i][j]=='.' and chk_zero(i,j):
					flag=1
					mat[i][j]='0'
					open_negh(i,j)
					tmp+=1
					#printmat()
					#print ' '
					#print i,j
		if flag==0:
			break
	for i in mat:
		tmp+=i.count('.')
	print 'Case #'+str(iii+1)+': ' +str(tmp)
