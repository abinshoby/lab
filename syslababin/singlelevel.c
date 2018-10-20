#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}dir;
void singlelevel()
{
int i,ch;
char f[30],new[30];

dir.fcnt = 0;
printf("\nEnter name of directory -- ");
scanf("%s", dir.dname);
while(1)
{
printf("\n\n 1. Create File\t2. Delete File\t3. Search File \n 4. Display Files \t 5.Rename file \t6. Exit\nEnter your choice -- ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter the name of the file -- ");
scanf("%s",f);
//scanf("%s",dir.fname[dir.fcnt]);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(f, dir.fname[i])==0)
{
printf("File %s already exists! ", f);
break;
}
}
if(i==dir.fcnt){
strcpy(dir.fname[dir.fcnt],f);
dir.fcnt++;
printf("\n File created.");}
break;
case 2: printf("\n Enter the name of the file -- ");
scanf("%s",f);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(f, dir.fname[i])==0)
{
printf("\n Are you sure to delete this file(y/n)");
char y;scanf("%s",&y);
if(y=='y'){
printf("File %s is deleted ",f);
strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
dir.fcnt--;}

break;
}
}
if(i==dir.fcnt+1)
printf("File %s not found",f);


break;
case 3: printf("\n Enter the name of the file -- ");
scanf("%s",f);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(f, dir.fname[i])==0)
{
printf("File %s is found ", f);
break;
}
}
if(i==dir.fcnt)
printf("File %s not found",f);
break;
case 4: if(dir.fcnt==0)
printf("\n Directory Empty");
else
{
printf("\n The Files are -- ");
for(i=0;i<dir.fcnt;i++)
printf("\t%s",dir.fname[i]);
}
break;
case 5:
printf("\n Enter the name of the file -- ");
scanf("%s",f);
for(i=0;i<dir.fcnt;i++)
{
if(strcmp(f, dir.fname[i])==0)
{
printf("File %s is found ", f);
printf("\n Enter new name:");
scanf("%s",new);
strcpy(dir.fname[i],new);
printf("\n File renamed successfully");
break;
}
}
if(i==dir.fcnt)
printf("File %s not found",f);
break;
default: exit(0);
}
}

}

