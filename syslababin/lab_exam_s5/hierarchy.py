class node:
	def __init__(self,name,typ):
		self.name=name
		self.typ=typ
		if(typ==0):
			self.next=None
		else:
			self.next=[]
	#def insert(self,name,typ):
		#if(typ==0):
		#	fil=node(name,typ)
		#	self.next.append(fil)
		#else:
		#	d=node(name,typ)
		#	self.next.append(d)

	
		
ch=0
root=node('root',1)
def find(next,d):
	for i in range(len( next)):
		if(next[i].name==d and next[i].typ==1):
			return i
	return -1

def create_f():
	print('Enter name of file')
	name=input()
	print('\n Enter path')
	path=input()
	paths=[]
	if(path=='/'):
		#paths.append('root')
		ff=node(name,0)
		root.next.append(ff)
	else:
		paths=path.strip().rstrip().split('/')
		print(paths)
		cur=root
		for d in paths[1:]:
			p=find(cur.next,d)
			if(p!=-1):
				cur=cur.next[p]
			else:	
				print('\n Invalid path');
		ff=node(name,0)
		cur.next.append(ff)
def create_d():
	
	print('Enter name of directory')
	name=input()
	print('\n Enter path')
	path=input()
	paths=[]
	if(path=='/'):
		paths.append('root')
		ff=node(name,1)
		root.next.append(ff)
	else:
		paths=path.split('/')
		cur=root
		for d in paths[1:]:
			p=find(cur.next,d)
			if(p!=-1):
				cur=cur.next[p]
			else:
				print('\n Invalid path');
		ff=node(name,1)
		cur.next.append(ff)
def search_f():
	print('Enter name of file')
	name=input()
	print('\n Enter path')
	path=input()
	paths=[]
	if(path=='/'):
		paths.append('root')
		for f in root.next:
			if(f.typ==0 and f.name==name):
				print('\n Found')
				return 1
		
		print('\n Not found')
		return -1
		
		
	else:
		paths=path.split('/')
		cur=root
		for d in paths[1:]:
			p=find(cur.next,d)
			if(p!=-1):
				cur=cur.next[p]
			else:
				print('\n Invalid path');
		for f in cur.next:
			if(f.typ==0 and f.name==name):
				print('\n Found')
				return 1
		print('not found')
		return -1;
		
def delete_f():
	print('Enter name of file')
	name=input()
	print('\n Enter path')
	path=input()
	paths=[]
	if(path=='/'):
		paths.append('root')
		for f in root.next:
			if(f.typ==0 and f.name==name):
				root.next.remove(f)
				print('\n deleted')
				return 1
		
		print('\n Not found')
		return -1
		
		
	else:
		paths=path.split('/')
		cur=root
		for d in paths[1:]:
			p=find(cur.next,d)
			if(p!=-1):
				cur=cur.next[p]
			else:
				print('\n Invalid path');
		for f in cur.next:
			if(f.typ==0 and f.name==name):
				cur.next.remove(f)
				print('\n deleted')
				return 1
		print('not found')
		return -1;
	
		
	

		
while(ch!=9):
	print('1.create file 2.delete file 3.search file 4.rename file 5.create directory 6.delete directory 7.rename directory 8.search directory 9.exit')	
	ch=int(input())
	if(ch==1):
		create_f()
	elif(ch==2):
		delete_f()
	elif(ch==3):
		search_f()
	elif(ch==4):
		rename_f()
	elif(ch==5):
		create_d()
	elif(ch==6):
		delete_d()
	elif(ch==8):
		search_d()
	elif(ch==7):
		rename_d()
	

