inp=raw_input();
words=inp.split(",")
# print words
newwords=[]
for i in words:
	# print i.split(";")
	newwords.extend(i.split(";"))
# print newwords
a=[]
b=[]
for i in newwords:
	if i.isdigit() and (i[0]!='0' or len(i)==1):
		a.append(i)
	else:
		b.append(i)

if(len(a)==0):
	print "-"
else:
	print '"' +','.join(a) + '"'

if(len(b)==0):
	print "-"
else:
	print '"' + ','.join(b) + '"'