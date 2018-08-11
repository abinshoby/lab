#include<stdio.h>
int q[10][5];
void sort(int a[10][5],int n){
	int temp0,temp1,temp2,temp3;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j][3]>a[j+1][3]){
				temp0=a[j][0];
				temp1=a[j][1];
				temp2=a[j][2];
				temp3=a[j][3];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j][2]=a[j+1][2];
				a[j][3]=a[j+1][3];
				a[j+1][0]=temp0;
				a[j+1][1]=temp1;
				a[j+1][2]=temp2;
				a[j+1][3]=temp3;
			}
		}
	}
}
void calc(int n){

	int cur_time=0;
	
	float tot_wait=0;
	int temp1,temp2,temp0,temp3;
	int tot=0;
	float tot_turn=0;
	int next[10][5];
	for(int i=0;i<n;i++){
	tot+=q[i][2];
	}
	for(int i=0;i<n;i++)
		q[i][4]=0;
	//sort by burst first
	sort(q,n);
	for(int i=0;i<n;i++)
		printf("\n %d %d %d %d",q[i][0],q[i][1],q[i][2],q[i][3]);
	while(cur_time!=tot){
		
		
		int i=0;
		while(i<n){
			if(q[i][4]==0&&q[i][1]<=cur_time){
				tot_wait+=cur_time-q[i][1];
				q[i][4]=1;
				cur_time+=q[i][2];
				i=0;
				
			}
			else
				i++;
		}
		cur_time++;

	}
		
		
	
	float avg_wait=(tot_wait/n);
	float avg_turn=((tot+tot_wait)/n);
	printf("\n avg waiting time:%f",avg_wait);
	printf("\n avg turn around time:%f",avg_turn);
}
void main(){
	int n;
	printf("\n Enter no of processes:");
	scanf("%d",&n);
	printf("Enter process id,arrival time,burst time,priority");
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&q[i][0],&q[i][1],&q[i][2],&q[i][3]);
	}
	
	calc(n);
	for(int i=0;i<n;i++){
		printf("\n %d %d %d %d",q[i][0],q[i][1],q[i][2],q[i][3]);
	}
}	
	
