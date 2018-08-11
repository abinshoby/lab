#include<stdio.h>
int q[10][4];
void sort (int a[10][4],int n){
	int temp0,temp1,temp2,temp3;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j][1]>a[j+1][1]){
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
int check(int n){
	for(int i=0;i<n;i++){
			if(q[i][2]!=0)
				return 1;
		}
		return 0;
}
void calculate(int n,int qt){
	sort(q,n);
	float tot_wait=0;
	int cur_wait=0;
	float tot=0;
	int i=0;
	for(int i=0;i<n;i++){
		tot+=q[i][2];
	}
	while(i<n){
		if(q[i][2]!=0&&q[i][1]<=cur_wait){
			tot_wait+=cur_wait-q[i][1];

			printf("%d:%f\n",q[i][0],tot_wait);
			if(q[i][2]<qt){
				
				cur_wait+=q[i][2];
				//q[i][1]+=q[i][2];
				q[i][1]=cur_wait;//-q[i][2];//m
				q[i][2]=0;
			}
			else{	
					cur_wait+=qt;
					q[i][2]-=qt;
					//q[i][1]+=qt;
					q[i][1]=cur_wait;//-qt;//m;
					
				}
		}
		i++;
		if(i==n&&check(n))
			i=0;
	}
	float tot_turn=tot+tot_wait;
	float avg_wait=tot_wait/n;
	float avg_turn=tot_turn/n;
	printf("\n Avg waiting time:%f",avg_wait);
	printf("\n Avg turnaround time:%f",avg_turn);
}

void main(){
	int n,qt;
	printf("\n Enter no of processes:");
	scanf("%d",&n);
	printf("\n Enter process id,arrival time,burst time");
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
	}
	printf("\n Enter time quanta:");
	scanf("%d",&qt);
	calculate(n,qt);
}

