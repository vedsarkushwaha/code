N=int(raw_input())
dict1={' ':0,'a':2,'b':22,'c':222,'d':3,'e':33,'f':333,'g':4,'h':44,'i':444,'j':5,'k':55,'l':555,'m':6,'n':66,'o':666,'p':7,'q':77,'r':777,'s':7777,'t':8,'u':88,'v':888,'w':9,'x':99,'y':999,'z':9999}
for j in xrange(1,N+1):
	inp=raw_input()
	out=''
	for i in range(len(inp)):
		if len(out)==0:
			out+=str(dict1[inp[i]])
		elif out[-1]==list(str(dict1[inp[i]]))[0] or (out[-1]==0 and inp[i]==' '):
			out+=(' '+str(dict1[inp[i]]))
		else:
			out+=str(dict1[inp[i]])
	print 'Case #'+str(j)+': '+out