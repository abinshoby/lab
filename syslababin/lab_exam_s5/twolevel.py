def create_d():
	print('Enter name of directory')
	name=input()
	l=[]
	if(name in root.keys()):
		print('Directory already exist')
	else:
		root[name]=l
		print('Directory created')
def create_f():
	print('Enter name of file')
	name=input()
	print('Enter name of directory')
	dire=input()
	if(name in root[dire]):
		print('File aready exist')
	else:
		root[dire].append(name)
		print('File created')
def delete_d():
	print('Enter name of directory')
	name=input()
	if(name in root.keys()):
		del root[name]
	else:
		print('Directory doesnt exist')
def delete_f():
	print('Enter name of file')
	name=input()
	print('Enter name of directory')
	dire=input()
	if(name in root[dire]):
		root[dire].remove(name)
	else:
		print('File doesnt exist')
def rename_f():
	print('Enter name of directory')
	dire=input()
	if(dire in root.keys()):
		print('Enter name of file')
		name=input()
		if(name in root[dire]):
			print('Enter new name')
			name1=input()
			root[dire].remove(name)
			root[dire].append(name1)
			print('File renamed')
		else:
			print('File not found')
	else:
		print('Directory not found')
def rename_d():
	print('Enter name of directory')
	name=input()
	if(name in root.keys()):
		temp=root[name]
		print('Enter ndew name')
		name1=input()
		del root[name]
		root[name1]=temp
		print('Direcyory renamed')
	else:
		print('Directory not found')
def search_f():
	print('enter directory')
	dire=input()
	if(dire in root.keys()):
		print('Enter name of file')
		name=input()
		if(name in root[dire]):
			print('Found')
		else:
			print('Not found')
	else:
		print('Invalid directory')
def search_d():
	print('Enter name of direcvtory')
	name=input()
	if(name in root.keys()):
		print('Found')
	else:
		print('not found')



root={}
ch=0
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
	

