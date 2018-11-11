#include<stdio.h>
int q[10];
void sort(int q[],int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(q[j]>q[j+1]){
				temp=q[j];
				q[j]=q[j+1];
				q[j+1]=temp;
			}
		}
	}
}
int sum(int a[],int n){
int s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	return s;
}
void main(){
	int n;
	int tot_wait=0;
	printf("\n Enter no of process:");
	scanf("%d",&n);
	printf("\n enter");
	for(int i=0;i<n;i++){
		scanf("%d",&q[i]);
	}
	sort(q,n);
	for(int i=0;i<n;i++){
		tot_wait+=sum(q,i);
	}
	printf("\n tot wait%f",((float)tot_wait)/n);
}
