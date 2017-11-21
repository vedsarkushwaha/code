import csv
# import set
limit = int(1500000)
mp = {}
st = set()

file = open("75.txt","r")
reader = csv.reader(file)
for row in reader:
	col = map(int, row)

	# generate all triplets
	i=0
	while(True):
		i+=1
		if sum([x*i for x in col]) > limit:
			break
		st.add(tuple([x*i for x in col]))

mp = {}

for i in st:
	# print i,sum(i)
	if sum(i) in mp:
		mp[sum(i)]+=1
	else:
		mp[sum(i)]=1


# 	sm = row[0]+row[1]+row[2]

# 	# all multiples of sm
# 	i=1
# 	mul = sm
# 	while(mul<=limit):
# 		if mul in mp:
# 			if (len(mp[mul])==1) and ([row[0]*i,row[1]*i,row[2]*i] != mp[mul][0]):
# 				mp[mul].append([row[0]*i,row[1]*i,row[2]*i])
# 		else:
# 			mp[mul]=[[row[0]*i,row[1]*i,row[2]*i]]
# 		i+=1
# 		mul = i*sm

sm=0
lst = []

for key, value in mp.iteritems():
	if value==1:
		sm+=1
print sm

file.close()