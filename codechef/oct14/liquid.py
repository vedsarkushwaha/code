T=int(raw_input())
for i in range(T):
	R,G,B,M=map(int,raw_input().split(' '))
	R=map(int,raw_input().split(' '))
	G=map(int,raw_input().split(' '))
	B=map(int,raw_input().split(' '))
	lst=map(max,[R,G,B])
	for i in range(M):
		lst[lst.index(max(lst))]/=2
	print max(lst)
