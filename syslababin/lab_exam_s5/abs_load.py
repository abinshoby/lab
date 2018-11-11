f=open('source.obj')
line=f.readline()
while(line!=''):
	lines=line.strip().split('^')
	if(lines[0]=='H'):
		print('\n Execution start at ',lines[2],'Program name:',lines[1],'Program length',lines[3])
	elif(lines[0]=='T'):
		sta=int('0x'+lines[1],16)
		for data in lines[3:]:
			print(hex(sta),'  -  ',data)
			sta+=int(len(data)/2)
		
		
	line=f.readline()
