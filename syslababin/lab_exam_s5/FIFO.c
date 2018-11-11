#include<stdio.h>
int find_frame(int frame[],int n,int a){
	for(int i=0;i<n;i++){
		if(frame[i]==a)
			return 1;
	}
	return -1;
}
int f=0;
int sz=0;
void insert(int frame[],int *n,int a){
	if(*n==sz){
		frame[f++]=a;
		if(f==sz+1){
			f=0;sz=0;
		}
	}
	else
		frame[sz++]=a;
}
void display(int frame[],int m){
	for(int i=0;i<m;i++)
		printf("\n%d", frame[i]);
}
void main(){
int ref[20];
int frame[10],fault=0,n,m;
printf("\n Ednter length of input string");
scanf("%d",&n);
printf("\n Enter frame size");
scanf("%d",&m);
printf("\n Enter");
for(int i=0;i<n;i++){
	scanf("%d",&ref[i]);
}
for(int i=0;i<n;i++){ 3
	if(find_frame(frame,m,ref[i])==-1){
		fault++;
		insert(frame,&m,ref[i]);
	}
	//display(frame,m);
}
printf("%d",fault);
}

