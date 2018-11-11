#include<stdio.h>
int sz=0;
int find_frame(int frame[][2],int m,int a){
	for(int i=0;i<sz;i++)
	{	if(frame[i][0]==a)
		return i;
	}
	return -1;
}
int find_min(int frame[][2]){
	int min=frame[0][1];
	int p=0;
	for(int i=0;i<sz;i++){
		if(frame[i][1]<min){
			p=i;
			min=frame[i][1];
		}
	}
	return p;
}
		
void insert(int frame[][2],int m,int a){
	if(sz==m){
		int p=find_min(frame);
		frame[p][0]=a;
		frame[p][1]=0;
	}
	else{
		frame[sz][0]=a;
		frame[sz++][1]=0;
	}
}
void main(){
	int r[20],frame[20][2],n,m,fault=0;
	printf("\n Enter length of string");
	scanf("%d",&n);
	printf("\n frame size");
	scanf("%d",&m);
	printf("\n Enter string");
	for(int i=0;i<n;i++){
		scanf("%d",&r[i]);
	}
	for(int i=0;i<n;i++){
		int p=find_frame(frame,m,r[i]);
		if(p==-1){
			insert(frame,m,r[i]);fault++;
		}
		else{
			frame[p][1]++;
		}
	}
	printf("\n %d",fault);
}

	
