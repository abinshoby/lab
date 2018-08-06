#include<stdio.h>
int q[10][3];
int sum_prev_burst(int n){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=q[i][2];
	return sum;
}

void sort(int a[10][3],int n){
	int temp0,temp1,temp2;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j][1]>a[j+1][1]){
				temp0=a[j][0];
				temp1=a[j][1];
				temp2=a[j][2];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j][2]=a[j+1][2];
				a[j+1][0]=temp0;
				a[j+1][1]=temp1;
				a[j+1][2]=temp2;
			}
		}
	}
}

void calc(int n){
	float avg_wait=0;
	float tot_wait=0;
	float tot_turn=0;
	float avg_turn=0;
	sort(q,n);
	for(int i=1;i<n;i++){
		int sum=sum_prev_burst(i);
		tot_wait+=sum-q[i][1];
		tot_turn+=sum+q[i][2]-q[i][1];
	}
	tot_turn+=q[0][2];
	avg_wait=tot_wait/n;
	avg_turn=tot_turn/n;
	printf("\n Avg waiting time %f ms",avg_wait);
	printf("\n Avg turnaround time:%f ms",avg_turn);
}

void main(){
	int n;
	printf("\n Enter no of processes:");
	scanf("%d",&n);
	printf("Enter process id ,arrival time,burst time");
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
	}
	calc(n);
}
		
