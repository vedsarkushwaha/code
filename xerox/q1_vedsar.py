def avg(l):
	a = 0.0
	for i in xrange(0, len(l)):
		a = a+l[i]
	a = a/len(l)
	return a

def getStockSpikesAndDips(string):
	if string.find('(') == -1 or string.find(',') == -1:
		return []
	string=string.lstrip('[')
	string=string.rstrip(']')
	lst=string.split("),(")
	lst[0]=lst[0].lstrip('(')
	lst[-1]=lst[-1].rstrip(')')
	l = [float(i.split(',')[1]) for i in lst]
	l1 = [int(i.split(',')[0]) for i in lst]
	dev = []
	avgl = avg(l)
	for i in xrange(len(l)):
		dev.append(abs(l[i] - avgl))
	avgDev = avg(dev)
	output = []
	if avgDev==0:
		ag=0
	else:
		ag=(avg(l)/avgDev)**(0.3)
	for i in xrange(len(l)):
		if dev[i]<=avgDev+ag:
			output.append("N");
		else:
			if (l[i] - avgl) > 0.0:
				output.append("S");
			else:
				output.append("D");
	out = []
	flag = 0
	for i in xrange(len(l)):
		if output[i] == "S":
			if flag == 0:
				lower = i+1  # 1-based indexing to be printed
				flag = 1
			elif flag == 2:
				out.append((lower, i))
				lower = i+1
				flag = 1
		elif output[i] == "D":
			if flag == 0:
				lower = i+1  # 1-based indexing to be printed
				flag = 2
			elif flag == 1:
				out.append((lower, i))
				lower = i+1
				flag = 2
		elif output[i] == "N":
			if flag != 0:
				out.append((lower, i))
				flag = 0
	if flag != 0:
		out.append((lower,len(l)))
	out = str(out).replace(' ', '')
	return out

if __name__=="__main__":
	string=raw_input()
	print getStockSpikesAndDips(string)