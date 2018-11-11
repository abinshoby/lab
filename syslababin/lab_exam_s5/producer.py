
def signal(s):
	s+=1
	return s
def wait(s):
	s-=1
	return s

def producer(f,e,mutex,item):
	mutex=wait(mutex) 
	
	
	if(e==0):
		print('Buffer full')
	else:
		f=signal(f)
		e=wait(e)
		item+=1
		print('Producer produces:',item)
	mutex=signal(mutex)
	return (f,e,mutex,item)
def consumer(f,e,mutex,item):
	mutex=wait(mutex)
	if(f==0):
		print('Buffer empty')
	else:
		e=signal(e)
		f=wait(f)
		
		print('Consumer consume:',item)
		item-=1
	mutex=signal(mutex)
	return (f,e,mutex,item)

	
ch=0
mutex=1
f=0
buf=[]
item=0
print('Enter buffer size')
n=int(input())
e=n

while(ch!=3):
	print('1.produce 2.consume 3.exit')
	ch=int(input())
	if(ch==1):
		(f,e,mutex,item)=producer(f,e,mutex,item)
	elif(ch==2):
		(f,e,mutex,item)=consumer(f,e,mutex,item)

	

