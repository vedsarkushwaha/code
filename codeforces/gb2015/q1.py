inp = map(str,raw_input().split(' '))
date = int(inp[0])
# print date, inp[1], inp[2]
if(inp[2]=="week"):
	if(date==5 or date==6):
		print 53
	else:
		print 52
else:
	if(date==31):
		print 7
	elif(date==30 or date==29):
		print 11
	else:
		print 12