def logic(plyr,mv,mat):
	#cutting move
	lst=[]
	for i in range(30-mv):
		if mat[i]==plyr and mat[i+mv]==nt(plyr):
			lst.append(i)
	#print lst
	while(len(lst)!=0):
		i=lst.pop()
		#print i
		if i+mv<26 and (mat[i+mv-1]!=nt(plyr) or mat[i+mv+1]!=nt(plyr)) and mat[i+mv]!=plyr:
			return i+1
    #defending move.
	#move to center of piece
	#print "def_cen"
	for i in range(2,30-mv):
		if(mat[i-1]==mat[i+1]==plyr and plyr!=mat[i]) and (mat[i-mv]==plyr and i-mv>=0) and i<26:
			return i-mv+1
	#move to left or right of piece
	#print "def_side"
	lst=[]
	for i in range(25):
		if mat[i]==mat[i+1]==plyr:
			lst.append(i)
	#print lst
	while(len(lst)!=0):
		i=lst.pop()
		#print i
		if i!=0 and i<24:
			if mat[i-1]=='.' or (weak_def(mat,i-1,nt(plyr)) and mat[i-1]!=plyr):
				if can_move(mat,plyr,i-1,mv):
					#print "e"
					return i-mv
			elif mat[i+2]=='.' or (weak_def(mat,i+2,nt(plyr)) and mat[i-1]!=plyr):
				if can_move(mat,plyr,i+2,mv):
					#print "l"
					return i-mv+3
    #26 reached move. This also check for 5
	if mat[25-mv]==plyr and not(mat[24]==mat[26]==nt(plyr)) and mat[25]!=plyr:
		return 25-mv+1
    #winning move. This also checks for 5
	if mat[-mv]==plyr:
		return 30-mv+1
	#26 above move
	if mat[25]==plyr and mv>1 and mat[25+mv]!=plyr:
		return 26
	#normal move
	#print "normal move"
	p_move=[]
	for i in range(25):
		#if mat[i+mv]=='.':
			#print i
		if mat[i]==plyr and i+mv<26 and (mat[i+mv]=='.' or (weak_def(mat,i+mv,nt(plyr)) and mat[i+mv]!=plyr)):
			p_move.append(i)
	plyr_pos=[]
	for i in range(30):
		if mat[i]==plyr:
			plyr_pos.append(i)
	#select that move which makes pieace close
	mn=-1
	for i in p_move:
		if mn==-1:
			mn=calc_diff(mat,plyr_pos,i,mv,plyr)
			fin_move=i
		else:
			temp=calc_diff(mat,plyr_pos,i,mv,plyr)
			if temp<mn:
				fin_move=i
	return fin_move+1

def calc_diff(mat,pos,slct,mv,plyr):
	sm=0;
	for i in pos:
		if i==slct:
			continue
	for j in pos[i+1:]:
		if j==slct:
			continue
		sm+=(j-i)
		for i in range(slct+1,30):
			if mat[i]==plyr:
				sm+=(i-slct)
	return sm
    
def weak_def(mat,pos,plyr):
	if (mat[pos]==mat[pos-1]==mat[pos+1]==plyr) and pos+1<26:
		return 0
	else:
		return 1
				
def can_move(mat,plyr,pos,mv):
	"""if plyr can move to pos"""
	if mat[pos-mv]==plyr and pos-mv>=0:
		return 1
	else:
		return 0
		
def nt(plyr):
	if plyr=='X':
		return 'O'
	else:
		return 'X'
	
if __name__=="__main__":
	plyr=raw_input().strip("\n")
	mv=int(raw_input())
	arr=[]
	temp=raw_input().strip("\n")
	arr.extend(list(temp))
	temp=raw_input().strip("\n")
	arr.extend((list(temp))[::-1])
	temp=raw_input().strip("\n")
	arr.extend(list(temp))
	print logic(plyr,mv,arr)
