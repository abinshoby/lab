#include "fcfs_disk.c"
#include "cscan_disk.c"
#include "scan_disk.c"
#include<stdio.h>
void main(){
	int c=-1;
	while(c!=4){
		printf("\n 1.FCFS 2.SCAN 3.CSCAN 4.EXIT");
		scanf("%d",&c);
		if(c==1)
			fcfs();
		else if(c==2)
			scan();
		else if(c==3)
			cscan();
		else;
	}
}
