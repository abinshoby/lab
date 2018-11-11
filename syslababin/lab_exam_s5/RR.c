#include<stdio.h>
int q[10][2];
int check(int q[][2],int n){
	for(int i=0;i<n;i++){
		if(q[i][0]>0)
			return 1;
	}
	return -1;
}
void display(int q[][2],int n){
	for(int i=0;i<n;i++)
		printf("%d %d\n",q[i][0],q[i][1]);
}
void main(){
	int n,ts,tot_wait=0,cur_time=0;
	printf("\n Enter no of process;");
	scanf("%d",&n);
	printf("\n Enter time quanta");
	scanf("%d",&ts);
	printf("\n enter");
	for(int i=0;i<n;i++){
		scanf("%d",&q[i][0]);
	}
	
	int p=1;
	int i=0;
	while(p!=-1){
		if(q[i][0]!=0)
			tot_wait+=cur_time-q[i][1];
		if(q[i][0]<ts){
			cur_time+=q[i][0];
			q[i][0]=0;

		}
		else{
			cur_time+=ts;
			q[i][0]-=ts;
		}
		
		q[i][1]=cur_time;
		printf("%d %d\n",q[i][0],q[i][1]);
		printf("tot wait:%d",tot_wait);	
		i++;
		if(i==n){
			i=0;printf("\n");
		}
		p=check(q,n);
		//display(q,n);
	}
	printf("\n Tot wait:%d",tot_wait+ts);
		
}

/*4 3 2 1 0
2 1 0 0 0
3 2 1 0 0
1 0 0 0 0*/





