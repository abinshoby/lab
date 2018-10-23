#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//DECLARATIONS
FILE* fp;
long len;
char *line=NULL;
char *opcode=NULL;
char *operand=NULL;
char *label=NULL;



void get_opcode(char *line,char *opcode);
void get_label(char *line,char *label);
void get_operand(char *line,char *operand);





void main(){
opcode=(char*)malloc(sizeof(char)*10);
operand=(char*)malloc(sizeof(char)*30);
label=(char*)malloc(sizeof(char)*30);
fp=fopen("source.asm","r");
char inp;
while(getline(&line, &len, fp)!=-1){
printf("Processing the line: %s",line);

get_opcode(line,opcode);

}
fclose(fp);
}

void get_opcode(char *line,char *opcode){
	char *token;
	//token = strtok(NULL, " ");
	
	token = strtok(line, " "); 
    //printf("\n %s",token);
    while (token != NULL) 
    { 	
        printf("\n%s ", token); token = strtok(NULL, " "); 
        
    }
  

}
