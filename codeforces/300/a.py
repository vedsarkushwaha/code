inp=str(raw_input())
opt="CODEFORCES"
for i in xrange(len(inp)):
	for j in xrange(len(inp)):
		tmp=inp[0:i]+inp[j+1:]
		if tmp==opt:
			print "YES"
			exit(0)
print "NO"