def fab(N):
	if(N==0):
		return 1
	if(N==1):
		return 2
	else:
		return fab(N-1)+fab(N-2)

# for i in range(100):
	# print fab(i)
print fab(38)

# 0 to 37