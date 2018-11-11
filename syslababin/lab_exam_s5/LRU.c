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
int find_in_s(int a,int n,int pos,int r[]){
	for(int i=pos-1;i>=0;i++){
			if(r[i]==a)
				return i;
	}
}
void insert(int frame[][2],int m,int a,int pos,int r[],int n){
	/*for(int i=0;i<sz;i++){
		int ps = find_in_s(frame[i][0],n,pos,r);
		frame[i][1]=ps;
	}*/
	if(sz==m){
		int p=find_min(frame);
		printf("\n %d",frame[p][0]);
		
		frame[p][0]=a;
		frame[p][1]=pos;
		//printf("hhh%d",a);
	}
	else{
		frame[sz][0]=a;
		frame[sz++][1]=pos;
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
			insert(frame,m,r[i],i,r,n);fault++;
		}
		else{
			frame[p][1]=i;
		}
	}
	printf("\n %d",fault);
}

	
