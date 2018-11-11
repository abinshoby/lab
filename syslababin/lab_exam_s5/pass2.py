OPTAB=[["ADD","18","3"],["ADDF","58","3"],["ADDR","90","2"],["AND","40","3"],["CLEAR","B4","2"],["COMP","28","3"],["COMPF","88","3"],      ["COMPR","A0","2"],["DIV","24","3"],["DIVF","64","3"],["DIVR","9C","2"],["FIX","C4","1"],["FLOAT","C0","1"],["HIO","F4","1"],["J","3C","3"],["JEQ","30","3"],["JGT","34","3"],["JLT","38","3"],["JSUB","48","3"],["LDA","00","3"],["LDB","68","3"],["LDCH","50","3"],["LDF","70","3"],["LDL","08","3"],["LDS","6C","3"],["LDT","74","3"],["LDX","04","3"],["LPS","D0","3"],["MUL","20","3"],["MULF","60","3"],["MULR","98","2"],
["NORM","C8","1"],["OR","44","3"],["RD","D8","3"],["RMO","AC","2"],["RSUB","4C","3"],["SHIFTL","A4","2"],["SHIFTR","A8","2"],["SIO","F0","1"],["SSK","EC","3"],["STA","0C","3"],["STB","78","3"],["STCH","54","3"],["STF","80","3"],["STI","D4","3"],["STL","14","3"],["STS","7C","3"],
["STSW","E8","3"],["STT","84","3"],["STX","10","3"],["SUB","1C","3"],["SUBF","5C","3"],["SVC","B0","2"],["SUBR","94","2"],["TD","E0","3"],
["TIO","F8","1"],["TIX","2C","3"],["TIXR","B8","2"],["WD","DC","3"]]
SYMTAB={}
HEADER='H^COPY^'

def load_symtab():
	f=open('symbol table.txt','r')
	line=f.readline().rstrip()
	while(line!=''):
		row=line.split('\t')
		SYMTAB[row[0]]=row[1]
		line=f.readline().rstrip()
	#print(SYMTAB)
def find_op(op):
	for i  in range(len(OPTAB)):
		if(OPTAB[i][0]==op):
			return i
	return -1


load_symtab()
inp=open('source.int','r')
line=inp.readline()
TR=''
def write_tr():
	global TR
	sz=0
	for e in TR[12:]:
		if(e=='^'):
			continue
		sz+=1
	sz/=2
	leng=hex(int(sz))[2:]

	TR=TR[:9]+leng+TR[11:]
	
	obj=open('source.obj','a')
	obj.write(TR+'\n')

def init_tr(loc):
	global TR
	loc=loc[2:]
	while(len(loc)<6):
		loc='0'+loc
	TR='T^'+loc+'^  ^'
def append_tr(obj):
	global TR
	TR=TR+obj+'^'
def check_fit(obj):
	global TR
	sz=0
	for e in TR[12:]:
		if(e=='^'):
			continue
		sz+=1
	sz+=len(obj)
	if(int(sz/2)>30):
		return False
	else:
		return True
def write_head():
	global HEADER
	obj=open('source.obj','w')
	obj.write(HEADER)

done=0	
	
while(line!=''):
	lines=line.split('\t')
	OBJ=''
	print(lines)
	if(lines[1]=='START'):
		HEADER+=lines[2]
		done=0
		write_head()
		init_tr(lines[0])
		TR=TR[:-1]

	else:
		if(find_op(lines[1])!=-1):
			done=0
			opera=lines[2].strip()
			if(opera==''):
				adr='0x0000'
			else:	
				adr=''
				if ',' in opera:
					opera2=opera.split(',')
					if(opera2[1]=='X'):
						if(opera2[0] in SYMTAB.keys()):
							a1=SYMTAB[opera2[0]]
							#print(a1)
							
							bina=(bin(int(a1,16))[2:])
							while(len(bina)<15):
								bina='0'+bina
							bina='1'+bina							
							
							#print(bina)
							#print(len(bina))
							adr=hex(int(bina,2))
						else:
							print('error')
					else:
						print('error')
				else:
					if(opera in SYMTAB.keys()):
							a1=SYMTAB[opera]
							bina=(bin(int(a1,16))[2:])
							while(len(bina)<=15):
								bina='0'+bina
							bina='0'+bina
							#print(len(bina))
							adr=hex(int(bina,2))
					else:
						print('error')
			OBJ=OPTAB[find_op(lines[1])][1]+adr[2:]
			print(line,':',OBJ)
		else:
			if(lines[1]=='BYTE'):
				done=0
				lines[2]=lines[2].strip()
				if(lines[2][0]=='C'):
					
					act=lines[2][2:len(lines[2])-1]
					hexv=''
					for c in act:
						hexv+=hex(ord(c))[2:]
					OBJ=hexv
				elif(lines[2][0]=='X'):
					OBJ=lines[2][2:len(lines[2])-1]
			elif(lines[1]=='WORD'):
				done=0
				lines[2]=lines[2].strip()
				hexv=''
				hexv=str(int(lines[2][:],16))
				while(len(hexv)<6):
					hexv='0'+hexv
				OBJ=hexv
			elif((lines[1]=='RESW' or lines[1]=='RESB')):
				if(done==0 ):
					write_tr()
					line=inp.readline()
					init_tr(lines[0])
					done=1
					continue
				else:
					line=inp.readline()
					continue
			
				
				

			print(OBJ)
	if(check_fit(OBJ)==False):
		write_tr()
		init_tr(lines[0])
	print('befre',TR)
	append_tr(OBJ)
	print(TR)	
				

				
	line=inp.readline()
	
	
