#include<stdio.h>
int abs(int n){
	if(n<0) return -1*n;
	else return n;
}
void main(){
	int n,head,q[10];
	printf("\nEnter size of q");
	scanf("%d",&n);
	printf("\n Enter current head position");
	scanf("%d",&head);
	printf("\n Enter quue");
	for(int i=0;i<n;i++){
		scanf("%d",&q[i]);
	}
	int tot=0;
	tot+=abs(q[0]-head);
	for(int i=0;i<n-1;i++)
		tot+=abs(q[i+1]-q[i]);
	printf("\n toata%d",tot);
}

	
