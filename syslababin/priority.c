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
	int temp0,temp1,temp2,temp3;
	int tot=0;
	float tot_turn=0;
	for(int i=0;i<n;i++){
		tot+=q[i][2];
	}
	for(int i=0;i<n;i++)
		q[i][4]=0;
	sort(q,n);
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
	}
	float avg_wait=tot_wait/n;
	float avg_turn=(tot+tot_wait)/n;
	printf("\n Avg waiting time:%f",avg_wait);
	printf("\n Avg turn around time:%f",avg_turn);
}
void main(){
	int n;
	printf("\n Ener no of processes:");
	scanf("%d",&n);
	printf("\n ENter proces id arrival time burst time ,priority");
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&q[i][0],&q[i][1],&q[i][2],&q[i][3]);
	calc(n);
}
		
				
				
