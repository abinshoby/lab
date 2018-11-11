#include<stdio.h>
int q[10];
int qs=0;
int tot_wait=0;
int sum(int a[],int n){
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	return s;
}
void main(){
	int n;
	printf("\n Enter no of process in queue");
	scanf("%d",&n);
	printf("\n Ener the burst time for each process in the order of request:\n");
	for(int i=0;i<n;i++){
		printf("\n process:%d",i);
		scanf(" %d",&q[i]);
		
	}
	for(int i=0;i<n;i++){
		tot_wait+=sum(q,i);
	}
	printf("\n total:=%d",tot_wait);
	float avg_wait=(((float)tot_wait)/n);
	printf("\nAvg waiting time:%f",avg_wait);
	int turn=0;
	for(int i=0;i<n;i++)
		turn+=q[i];
	turn+=tot_wait;
		printf("\n turn around%f",((float)turn/4));
}
	
		
