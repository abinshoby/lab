
d=[]
print('Enter name of directory');
main=input()

def find(d,n):
	if(n  in d):
		for i in range(len(d)):
			if(d[i]==n):
				return i
	else:
		return -1
def create_f():
	print('Enter name of file')
	name=input()
	if(find(d,name)==-1):
		d.append(name)
		print('\n File created')
	else:
		print('\n File already exist')
def delete_f():
	print('Enter name of file')
	name=input()
	if(find(d,name)==-1):
		print("\n file doesn't exist")
	else:
		d.remove(name)
		print('\n File deleted');
def rename_f():
	print('Enter name of file')
	name=input()
	print('Enter new name of file')
	name1=input()
	if(find(d,name)==-1):
		print('File doesnt exist')
	else:
		d[find(d,name)]=name1
		print('File renamed')
def search_f():
	
	print('Enter name of file')
	name=input()
	if(find(d,name)==-1):
		print('file not found')
	else:
		print('File found')

		

	
ch=0
while(ch!=4):
	print('1.create file 2.delete file 3.search file 4.rename file 5.exit')	
	ch=int(input())
	if(ch==1):
		create_f()
	elif(ch==2):
		delete_f()
	elif(ch==3):
		search_f()
	elif(ch==4):
		rename_f()

