game=[]

pieces={}
pieces['1a']=[["----"],["----"],["----"],["####"]]
pieces['1b']=[["#---"],["#---"],["#---"],["#---"]]
pieces['2a']=[["----"],["----"],["#---"],["###-"]]
pieces['2b']=[["----"],["-#--"],["-#--"],["##--"]]
pieces['2c']=[["----"],["##--"],["#---"],["#---"]]
pieces['2d']=[["----"],["----"],["###-"],["--#-"]]
pieces['3a']=[["----"],["----"],["--#-"],["###-"]]
pieces['3b']=[["----"],["#---"],["#---"],["##--"]]
pieces['3c']=[["----"],["----"],["###-"],["#---"]]
pieces['3d']=[["----"],["##--"],["#---"],["#---"]]
pieces['4a']=[["----"],["----"],["##--"],["##--"]]
pieces['5a']=[["----"],["----"],["-##-"],["##--"]]
pieces['5b']=[["#---"],["#---"],["##--"],["-#--"]]
pieces['6a']=[["----"],["----"],["-#--"],["###-"]]
pieces['6b']=[["----"],["#---"],["##--"],["#---"]]
pieces['6c']=[["----"],["----"],["###-"],["-#--"]]
pieces['6d']=[["----"],["-#--"],["##--"],["-#--"]]
pieces['7a']=[["----"],["----"],["##--"],["-##-"]]
pieces['7b']=[["----"],["-#--"],["##--"],["#---"]]

def getPosition(pce,rot):
	None

if __name__=="__main__":
	bestRot='nd'
	lst=raw_input().split()
	if(len(lst)==2):
		tp,pce=lst[0],lst[1]
	else:
		tp,pce,bestRot=lst[0],lst[1],lst[2]

	if(bestRot!='nd'):
		bestI,bestJ,rtng=getPosition(pce,bestRot)
	else:
		mxrtng=float(0)
		bestI,bestJ=0,0
		for rot in ['a','b','c','d']:
			i,j,rtng=getPosition(pce,rot)
			if(rtng>mxrtng):
				bestI=I
				bestJ=J
				bestRot=rot
	# note that bestI, bestJ should be pcs leftmost and down most co-ordinates
	print rot,bestI,bestI