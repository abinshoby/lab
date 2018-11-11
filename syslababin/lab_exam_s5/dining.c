#include<stdio.h>
typedef struct philosopher{
	int state;
	int leftcs,rightcs;
}d1;
d1 d[5];
//int chopstick[5];

void think(int no){
	d[no].state=0;
	//if(chopstick[(no+4)%5]&&chopstick[(no)%5]
	
	//if(d[(no+1)%5].leftcs==0)
		d[no].rightcs=0;
	//if(d[(no+4)%5].rightcs==0)
		d[no].leftcs=0;
	d[no].state=0;
	printf("\n %d thinking",no);
}
void eat(int no){
	if(d[(no+1)%5].leftcs==0&&d[(no+4)%5].rightcs==0&&d[no].state==1){
			d[no].rightcs=1;
			d[no].leftcs=1;
	
			d[no].state=2;//eating
			printf("\n %d eating",no);
	}
}
void sethungry(int no){
	d[no].state=1;
printf("\n %d hungry",no);
}
void main(){
	for(int i=0;i<5;i++)
		think(i);
	int ch,no;
	while(ch!=4){
	printf("\n 1.Think 2.Eat 3.set hungry 4.exit");
		scanf("%d",&ch);
	if(ch==1)
	{
		printf("\n Enter philosopher[0-5]");
		scanf("%d",&no);
		think(no);
	}
	else if(ch==2){
		printf("\n Enter philosopher[0-5]");
		scanf("%d",&no);
		eat(no);
	}
	else if(ch==3){
		printf("\n Enter philosopher[0-5]");
		scanf("%d",&no);
		sethungry(no);
	}

	}
}
	
	
