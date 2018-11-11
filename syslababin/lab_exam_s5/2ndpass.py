OPTAB=[["ADD","18","3"],["ADDF","58","3"],["ADDR","90","2"],["AND","40","3"],["CLEAR","B4","2"],["COMP","28","3"],["COMPF","88","3"],      ["COMPR","A0","2"],["DIV","24","3"],["DIVF","64","3"],["DIVR","9C","2"],["FIX","C4","1"],["FLOAT","C0","1"],["HIO","F4","1"],["J","3C","3"],["JEQ","30","3"],["JGT","34","3"],["JLT","38","3"],["JSUB","48","3"],["LDA","00","3"],["LDB","68","3"],["LDCH","50","3"],["LDF","70","3"],["LDL","08","3"],["LDS","6C","3"],["LDT","74","3"],["LDX","04","3"],["LPS","D0","3"],["MUL","20","3"],["MULF","60","3"],["MULR","98","2"],
["NORM","C8","1"],["OR","44","3"],["RD","D8","3"],["RMO","AC","2"],["RSUB","4C","3"],["SHIFTL","A4","2"],["SHIFTR","A8","2"],["SIO","F0","1"],["SSK","EC","3"],["STA","0C","3"],["STB","78","3"],["STCH","54","3"],["STF","80","3"],["STI","D4","3"],["STL","14","3"],["STS","7C","3"],
["STSW","E8","3"],["STT","84","3"],["STX","10","3"],["SUB","1C","3"],["SUBF","5C","3"],["SVC","B0","2"],["SUBR","94","2"],["TD","E0","3"],
["TIO","F8","1"],["TIX","2C","3"],["TIXR","B8","2"],["WD","DC","3"]]
SYMTAB=[]
HEADER='H^COPY^'
OBJ=''
TR=''
def append_tr():
	print(OBJ)
	return ('^'+OBJ)
def search_symtab(label):
	i=0
	for row in SYMTAB:
		if(row[0]==label):
			return i
		i+=1
	return -1
def search_optab(opcode):
	i=0
	for row in OPTAB:
		if(row[0]==opcode):
			return i
		i+=1
	return -1
def load_symtab():
	f=open('symbol table.txt','r')
	line=f.readline().rstrip()
	while(line!=''):
		row=line.split('\t')
		SYMTAB.append(row)
		line=f.readline().rstrip()
	#print(SYMTAB)
def assemble(opcode,index,adr):
	return (opcode+str(hex(int(str(index)+bin(int(adr,16)).replace('0b',''),2))))
def init_TR():
	TR='T^    ^'
def write_header():
	f=open('source.obj','a')
	f.write(HEADER+'\n')
def convert(operand):
	hex_val=''
	if(operand[0]=='C'):
		val=operand[2:len(operand)-1]
		for c in val:
			hex_val+=(str(int(ord(c),16)).replace('0x',''))
	elif(operand[0]=='X'):
		hex_val=operand[2:len(operand)-1]
	return hex_val
def write_tr():
	f=open('source.obj','a')
	f.write(TR+'\n')

def check_fit():
	if(len(OBJ)+len(TR)-TR.count('^')<=69):
		return True
	else:
		return False	
	
load_symtab()	
inter=open('source.int','r')
line=inter.readline().rstrip()
lineno=0
init_TR()
while(line!=''):
	row=line.split('\t')
	print(row)
	if(lineno==0):
		if(row[1]=='START'):
			if(len(row)==3):
				HEADER+=row[2]+'^'
			else:
				HEADER+='000000^'
		else:
			HEADER+='000000^'
		write_header()
	
	if(row[1]!='START' and row[1]!='END'):
		op=search_optab(row[1])
		if(op!=-1):
			if(len(row)>2):#opernd is present	
				cm=row[2].find(',')
			
				if(cm==-1):#no index
					sp=search_symtab(row[2])
					print('hhh',row[2])
					if(sp!=-1):
						OBJ=assemble(OPTAB[sp][1],0,SYMTAB[sp][1])
						
					else:
						OBJ=assemble(OPTAB[sp][1],0,'0x0000')
						print('error')
						print('here',OBJ)
				else:
					sp=search_symtab(row[2][:cm])
					if(sp!=-1):
						OBJ=assemble(OPTAB[sp][1],1,SYMTAB[sp][1])
					else:
						OBJ=assemble(OPTAB[sp][1],1,'0x0000')
						print('error')
			else:#operand not present
				OBJ=assemble(OPTAB[sp][1],0,'0x0000')
		elif(row[1]=='BYTE' or row[1]=='WORD'):
			OBJ=convert(row[1])
		elif(row[1]=='RESW' or row[1]=='RESB'):
			write_tr()
			init_TR()
		if(check_fit()==False):
			write_tr()
			init_TR()
		TR+=append_tr()
	if(row[1]=='END'):
		write_tr()
		#write_er()
	
	line=inter.readline().rstrip()
	lineno+=1		
			
				
					
		
	
		
			
			
	

