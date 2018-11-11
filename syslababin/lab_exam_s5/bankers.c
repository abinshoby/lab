#include<stdio.h>

int allocation[10][5];
int max[10][5];
int need[10][5];
int work[5];
int aval[5];
int n;
int m;

void modify(){
	printf("\n no of process;");
	scanf("%d",&n);
	printf("\n no of resources");
	scanf("%d",&m);
	printf("\n Enter availbale");
	for(int i=0;i<m;i++)
		scanf("%d",&aval[i]);
	printf("\n Enter maximum");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			scanf("%d",&max[i][j]);
	}
	printf("\n Ener allocation");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			scanf("%d",&allocation[i][j]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			need[i][j]=max[i][j]-allocation[i][j];
	}
}
int find_i(int finish[10]){
	int p=-1;
	for(int i=0;i<n;i++){
		int s=0;
		for(int j=0;j<m;j++){
			if(need[i][j]<=work[j])
				s=1;
			else
			{s=0;break;}
		}
		if(s==1){
			if(finish[i]==0)
			{p=i;break;}
			else
				p=-1;
		}
		else
			p=-1;
	}
	return p;
}

		
int safety(){
	int finish[10];int s;
	for(int i=0;i<n;i++)
		finish[i]=0;
	for(int i=0;i<m;i++)
		work[i]=aval[i];
	int i=0;
	while(1){
		int p=find_i(finish);
		if(p==-1)
			break;
		else{	printf("\n %d",p);
			for(int i=0;i<m;i++)
				work[i]+=allocation[p][i];
			finish[p]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(finish[i]==1)
			s=1;
		else{
			s=0;
			printf("\n NOt safe");
			break;
		}
	}
	if(s==1){
		printf("\n safe");return 1;
	}
	else{
		return -1;
	}
}
int request(){
	int request[3];
	int pr;
	printf("\n Enter the process no:");
	scanf("%d",&pr);
	int s=0;
	printf("\n Enter resource requested:");
	for(int i=0;i<m;i++)
		scanf("%d",&request[i]);
	for(int i=0;i<m;i++){
		if(need[pr][i]>=request[i])
			s=1;
		else{
			printf("\n resource exceed max claim");return -1;s=0;break;
		}
	}
	s=0;
	for(int i=0;i<m;i++){
		if(request[i]<=aval[i])
			s=1;
		else{
			s=0;printf("\n Process should wait");
			return -1;break;
		}
	}
	for(int i=0;i<m;i++)
		aval[i]=aval[i]-request[i];
	for(int i=0;i<m;i++)
		need[pr][i]-=request[i];
	for(int i=0;i<m;i++)
		allocation[pr][i]+=request[i];
	int p=safety();
	if(p==-1){
		printf("\n cannot give request");return -1;}
	else{
		printf("\n request granted");return 1;}
}
	
	

void main(){
	int ch;
	while(ch!=4){
		printf("\n 1.Modify state 2. safety check 3.request 4 exit\n");
		scanf("%d",&ch);
		if(ch==1){
			modify();
		}
		else if(ch==2)
			safety();
		else if(ch==3)
			request()
			;
	}
}
		
