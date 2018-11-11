OPTAB=[["ADD","18","3"],["ADDF","58","3"],["ADDR","90","2"],["AND","40","3"],["CLEAR","B4","2"],["COMP","28","3"],["COMPF","88","3"],      ["COMPR","A0","2"],["DIV","24","3"],["DIVF","64","3"],["DIVR","9C","2"],["FIX","C4","1"],["FLOAT","C0","1"],["HIO","F4","1"],["J","3C","3"],["JEQ","30","3"],["JGT","34","3"],["JLT","38","3"],["JSUB","48","3"],["LDA","00","3"],["LDB","68","3"],["LDCH","50","3"],["LDF","70","3"],["LDL","08","3"],["LDS","6C","3"],["LDT","74","3"],["LDX","04","3"],["LPS","D0","3"],["MUL","20","3"],["MULF","60","3"],["MULR","98","2"],
["NORM","C8","1"],["OR","44","3"],["RD","D8","3"],["RMO","AC","2"],["RSUB","4C","3"],["SHIFTL","A4","2"],["SHIFTR","A8","2"],["SIO","F0","1"],["SSK","EC","3"],["STA","0C","3"],["STB","78","3"],["STCH","54","3"],["STF","80","3"],["STI","D4","3"],["STL","14","3"],["STS","7C","3"],
["STSW","E8","3"],["STT","84","3"],["STX","10","3"],["SUB","1C","3"],["SUBF","5C","3"],["SVC","B0","2"],["SUBR","94","2"],["TD","E0","3"],
["TIO","F8","1"],["TIX","2C","3"],["TIXR","B8","2"],["WD","DC","3"]]

SYMTAB=[]
def write_int(LOCCTR,opcode,operand,filename):
	out=open(filename,'a')
	linet=hex(LOCCTR)+'\t'+opcode+'\t'+operand+'\n'
	out.write(linet)
	
def search_symtab(label):
	for row in SYMTAB:
		if(row[0]==label):
			return -1
	return 1
			
				
def search_optab(opcode):
	for row in OPTAB:
		if(row[0]==opcode):
			return 1
	return -1
def calc_length(operand):
	byte_v=""
	if(operand[0]=='C'):
		val=operand[2:len(operand)-1]
		#print('herelll',val)
		for c in val:
			byte_v+=str(hex(ord(c)))
			return len(val)
			
	elif(operand[0]=='X'):
		byte_v=operand[2:len(operand)-1]
		return int(len(byte_v)/2)

		
		
def write_symtab():
	f=open('symbol table.txt','w')
	for row in SYMTAB:
		f.write(row[0]+'\t'+row[1]+'\n')
			
		
source=open('source.asm','r')
filename='source.int'
line=source.readline().rstrip('\n')
parts=[]
START_ADDRESS=0x0000
LOCCTR=0X0000
lineno=0
while(line is not ""):
	print('Assembling:',line);
	parts=line.split("\t")
	#print(parts)
	
	if(len(parts)>1 and parts[1]=='START' ):
		if(len(parts)==2):#no operand
			LOCCTR=0x0000
		else:
			LOCCTR=(int((parts[2]),16))
		
		write_int(LOCCTR,parts[1],parts[2],filename)
		line=source.readline().rstrip('\n')
		lineno+=1
		continue
	else:
		if(lineno==0):
			LOCCTR=0x0000
	temp=LOCCTR
	if(parts[0]!='.'):#not coment line
		if(parts[0]!=''):
			if(search_symtab(parts[0])==-1):
				print('error');
			else:
				SYMTAB.append([parts[0],hex(LOCCTR)])
		if(search_optab(parts[1])==1):
			LOCCTR+=3
		elif(parts[1]=='WORD'):
			LOCCTR+=3
		elif(parts[1]=='RESW'):
			LOCCTR+=3*(int(parts[2]))
		elif(parts[1]=='RESB'):
			LOCCTR+=(int(parts[2]))
		elif(parts[1]=='BYTE'):
			LOCCTR+=calc_length(parts[2])
		elif(parts[1]=='END'):
			print('pass1 complete')
		else:
			print('error')
		if(len(parts)==2):#rsub
			write_int(temp,parts[1],"",filename)
		else:
			write_int(temp,parts[1],parts[2],filename)
	lineno+=1
	
	line=source.readline().rstrip('\n')
write_symtab()
