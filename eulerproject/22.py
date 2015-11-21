def fun(name):
	lst=list(name)
	tmp=0
	for i in lst:
		tmp+=(ord(i)-64)
	return tmp

if __name__=="__main__":
	fp=open("names.txt")
	ln=fp.readline()
	lst=ln.split(",")
	lst=[x.strip('"') for x in lst]
	lst.sort()
	ttl=0
	for i in xrange(len(lst)):
		ttl+=((i+1) * fun(lst[i]))
	print ttl