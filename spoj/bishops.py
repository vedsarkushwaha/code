import sys

if __name__=="__main__":
	for line in sys.stdin:
		if int(line)==0:
			print "0"
		elif int(line)==1:
			print "1"
		else:
			print int(line)*2-2
