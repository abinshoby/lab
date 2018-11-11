#include<stdio.h>
void sort(int q[],int n){int temp;
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
int abs(int n){
	if(n<0) return -1*n;
	else return n;
}				;

void main(){
	int q[10],end,head, n;
	printf("\n Enter the initial hgead position");
	scanf("%d",&head);
	printf("\n Enter size of q");
	scanf("%d",&n);
	printf("\n Enter last cykinder no");
	scanf("%d",&end);
	printf("\n Enter elemrnts;");
	for(int i=0;i<n;i++)
		scanf("%d",&q[i]);
	int tot=0;
	sort(q,n);
	int p;
	for(int i=0;i<n;i++)
	{	if(q[i]>=head){
			p=i;break;
		}
	}
	tot+=abs(q[p]-head);
	for(int i=p;i<n-1;i++)
		tot+=abs(q[i+1]-q[i]);
	tot+=abs(q[n-1]-end);
	tot+=abs(end-q[p-1]);
	for(int i=p-1;i>0;i--)
		tot+=abs(q[i]-q[i-1]);
	printf("\n Total%d",tot);
}
	
			


