/*1) Let Work and Finish be vectors of length ‘m’ and ‘n’ respectively.
Initialize: Work = Available
Finish[i] = false; for i=1, 2, 3, 4….n

2) Find an i such that both
a) Finish[i] = false
b) Needi <= Work if no such i exists goto step (4)

3) Work = Work + Allocation
Finish[i] = true
goto step (2)

4) if finish [i] = true for all i
then the system is in a safe state*/

/*1) If Requesti <= Needi
Goto step (2) ; otherwise, raise an error condition, since the process has exceeded its maximum claim.

2) If Requesti <= Available Goto step (3); otherwise, Pi must wait, since the resources are not available.

3) Have the system pretend to have allocated the requested resources to process Pi by modifying the state as
follows:
Available = Available – Requesti
Allocationi = Allocationi + Requesti
Needi = Needi– Requesti*/
#include<stdio.h>
int m,n;
int available[10];//m
int find_satisfying(int need[20][10],int work[10],int finish[20],int m,int n){
	int s,f;
	


	for(int i=0;i<n;i++){
		s=-1;
		f=0;
		if(finish[i]==0){
			f=1;
			for(int j=0;j<m;j++){
				if(need[i][j]<=work[j]){
					s=i;
					
				}
				else{
					s=-1;
					break;
					
				}
			}
			if(s>=0)
				return s;
		}

		else
			f=0;
		
		if(s>=0&&f==1)
			break;
	}
	return s;
}
int safety(int need[20][10],int allocation[20][10],int m,int n){
	int work[10];
	for(int i=0;i<m;i++)
		work[i]=available[i];
	int finish[20];//n
	for(int i=0;i<n;i++)
		finish[i]=0;
	int p=0;
	p=find_satisfying(need,work,finish,m,n);
	while(p!=-1){
		
		for(int j=0;j<m;j++){
		
			
			work[j]=work[j]+allocation[p][j];
		}
		finish[p]=1;
		//printf("%d",p);
		p=find_satisfying(need,work,finish,m,n);
		
	}
	int f;
	for(int i=0;i<n;i++){
		if(finish[i]==0){
			f=0;
			break;
		}
		else
			f=1;
	}
	if(f==1){
		printf("\n system is in safe state");
		return 1;
	}
	else{
		printf("\n system is not in safe state");
		return 0;
	}
}
int safe_sequence(int need[20][10],int allocation[20][10],int m,int n){
	int work[10];
	for(int i=0;i<m;i++)
		work[i]=available[i];
	int finish[20];//n
	for(int i=0;i<n;i++)
		finish[i]=0;
	int p=0;
	p=find_satisfying(need,work,finish,m,n);
	printf("\n Safe sequence:");
	while(p!=-1){
		
		for(int j=0;j<m;j++){
		
			
			work[j]=work[j]+allocation[p][j];
		}
		finish[p]=1;
		printf("%d\t",p);
		p=find_satisfying(need,work,finish,m,n);
		
	}
	int f;
	for(int i=0;i<n;i++){
		if(finish[i]==0){
			f=0;
			break;
		}
		else
			f=1;
	}
	if(f==1){
		printf("\n system is in safe state");
		return 1;
	}
	else{
		printf("\n system is not in safe state");
		return 0;
	}
}
void request(int max[20][10],int allocation[20][10],int request[10],int m,int n,int t){
int f;
int need[20][10];
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++)
		need[i][j]=max[i][j]-allocation[i][j];
}
for(int i=0;i<m;i++){
	if(request[i]<=need[t][i])
		f=1;
	else{
		f=0;
		break;
	}
}
if(f==1){
	int s;
	for(int i=0;i<m;i++){
		if(request[i]<=available[i])
			s=1;
		else{
			s=0;
			break;
		}
	}
	if(s==1){
		int temp[10];
		for(int i=0;i<m;i++){
			temp[i]=available[i];//preserve available
			available[i]=available[i]-request[i];
			need[t][i]=need[t][i]-request[i];
			allocation[t][i]=allocation[t][i]+request[i];
		}
		if(safety(need,allocation,m,n)==1){
			printf("\n request is granted");
		}
		else{
			printf("\n request cannot be granted");
			//preserve old state
			for(int i=0;i<m;i++){
				available[i]=temp[i];
				allocation[t][i]=allocation[t][i]-request[i];
			}
			
		}
	}
	else
		printf("\n The process should wait");
}
else
	printf("\n process exceeds its maximum claim");
}

void main(){
	int max[20][10],allocation[20][10],m,n,req[10],no,c=0;
	while(c!=4){
		printf("\n 1.Modify the system state 2.Request a resource 3.Find safe sequence 4.Exit");
		scanf("%d",&c);
		if(c==1){
			printf("\n Enter no of different types of  resources and no of processes:");
			scanf("%d%d",&m,&n);
			printf("\n Enter no of instances of each resource:");
			for(int i=0;i<m;i++)
				scanf("%d",&available[i]);
			printf("\n Enter maximum no of instances of each resource allotted to each process:");
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
					scanf("%d",&max[i][j]);
			}
			printf("\n Enter current allocation state:");
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
					scanf("%d",&allocation[i][j]);
			}
		}
		else if(c==2){
		
			printf("\n Enter the id of the process  requesting the resource:");
			scanf("%d",&no);
			printf("\n Enter the no of instances of each resource that it needs:");
			for(int i=0;i<m;i++)
				scanf("%d",&req[i]);
			request(max,allocation,req,m,n,no);
		}
		else if(c==3){
			int need[20][10];
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
					need[i][j]=max[i][j]-allocation[i][j];
				}
			safe_sequence(need,allocation,m,n);
			
		}
		else;
	}


}

	




	
	
	
	


