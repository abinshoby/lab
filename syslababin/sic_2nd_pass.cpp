#include<string.h>
#include<iostream>
#include<stdio.h>
#include<algorthm>
#include<fstream>
using namespace std;

int LOCCTR=0;
int STARTADRESS=0;
string SYMTAB[100][2];
int symtabsz=0;
int error=0;
int optabsz=59;//101;
int PGM_LENGTH;
string OPTAB[][3]={
	{"ADD","18","3"},
	{"ADDF","58","3"},
	{"ADDR","90","2"},
	{"AND","40","3"},
	{"CLEAR","B4","2"},
	{"COMP","28","3"},
	{"COMPF","88","3"},
	{"COMPR","A0","2"},
	{"DIV","24","3"},
	{"DIVF","64","3"},
	{"DIVR","9C","2"},
	{"FIX","C4","1"},
	{"FLOAT","C0","1"},
	{"HIO","F4","1"},
	{"J","3C","3"},
	{"JEQ","30","3"},
	{"JGT","34","3"},
	{"JLT","38","3"},
	{"JSUB","48","3"},
	{"LDA","00","3"},
	{"LDB","68","3"},
	{"LDCH","50","3"},
	{"LDF","70","3"},
	{"LDL","08","3"},
	{"LDS","6C","3"},
	{"LDT","74","3"},
	{"LDX","04","3"},
	{"LPS","D0","3"},
	{"MUL","20","3"},
	{"MULF","60","3"},
	{"MULR","98","2"},
	{"NORM","C8","1"},
	{"OR","44","3"},
	{"RD","D8","3"},
	{"RMO","AC","2"},
	{"RSUB","4C","3"},
	{"SHIFTL","A4","2"},
	{"SHIFTR","A8","2"},
	{"SIO","F0","1"},
	{"SSK","EC","3"},
	{"STA","0C","3"},
	{"STB","78","3"},
	{"STCH","54","3"},
	{"STF","80","3"},
	{"STI","D4","3"},
	{"STL","14","3"},
	{"STS","7C","3"},
	{"STSW","E8","3"},
	{"STT","84","3"},
	{"STX","10","3"},
	{"SUB","1C","3"},
	{"SUBF","5C","3"},
	{"SVC","B0","2"},
	{"SUBR","94","2"},
	{"TD","E0","3"},
	{"TIO","F8","1"},
	{"TIX","2C","3"},
	{"TIXR","B8","2"},
	{"WD","DC","3"}
	


	/*{"+ADD","18","4"},
        {"+ADDF","58","4"},
       
        {"+AND","40","4"},
        
        {"+COMP","28","4"},
        {"+COMPF","88","4"},
        
        {"+DIV","24","4"},
        {"+DIVF","64","4"},
        
        
       
        
        {"+J","3C","4"},
        {"+JEQ","30","4"},
        {"+JGT","34","4"},
        {"+JLT","38","4"},
        {"+JSUB","48","4"},
        {"+LDA","00","4"},
        {"+LDB","68","4"},
        {"+LDCH","50","4"},
        {"+LDF","70","4"},
        {"+LDL","08","4"},
        {"+LDS","6C","4"},
        {"+LDT","74","4"},
        {"+LDX","04","4"},
	{"+LPS","D0","4"},
        {"+MUL","20","4"},
        {"+MULF","60","4"},
     
        
        {"+OR","44","4"},
        {"+RD","D8","4"},
        
        {"+RSUB","4C","4"},
        
        
     
        {"+SSK","EC","4"},
        {"+STA","0C","4"},
        {"+STB","78","4"},
        {"+STCH","54","4"},
        {"+STF","80","4"},
        {"+STI","D4","4"},
        {"+STL","14","4"},
        {"+STS","7C","4"},
        {"+STSW","E8","4"},
        {"+STT","84","4"},
        {"+STX","10","4"},
        {"+SUB","1C","4"},
        {"+SUBF","5C","4"},
       
       
        {"+TD","E0","4"},
       
        {"+TIX","2C","4"},
        
        {"+WD","DC","4"}*/


	};
int search_optab(string opcode){
	for(int i=0;i<optabsz;i++){
		if(OPTAB[i][0].compare(opcode)==0)
			return i;
	}
	return -1;
}

int search_symtab(string label){
	for(int i=0;i<symtabsz;i++){
		if(SYMTAB[i][0].compare(label)==0)
			return 1;
	}
	return 0;
}
string load_pgm_length(){
	fstream	pgm_l;
	pgm_l.open("program_length.txt",ios::in);
	string l;
	pgm_l>>l;
	pgm_l.close();
	return l;
}
void load_symtab(){
fstream symtab;
string symbol,val;
symtab.open("symbol_table.txt",ios::in);
if(symtab.is_open())
{       

		while (getline(symtab, line))
		{	if(line.compare("")==0){
				break;
			}
			stringstream ss(line);
    	
    		if(ss >> symbol>>val;)
    		{
				;
		
			}
			SYMTAB[symtabsz][0]=symbol;
			SYMTAB[symtabsz][1]=val;
			symtabsz++;
		}
		
			
			
}
symtab.close();
}


int pass2(int lineno,string loc,string opcode,string operand,char argv[]){
	//do here

}
int main(int *argc,char *argv[]){
	load_symtab();
	PGM_LENG=load_pgm_length();
	fstream intermediate;
	string line,loc,opcode,operand;
	int lineno=0;
	source.open(argv[1],ios::in);
	
	fstream obj;
	
	
	char ff2[20];
	int i;
	strcpy(ff2,argv[1]);
	for(i=0;i<strlen(argv[1]);i++){
		if(ff2[i]=='.')
			break;
	}
	ff2[i]='.';
	ff2[i+1]='o';
	ff2[i+2]='b';
	ff2[i+3]='j';
	obj.open(ff2,ios::out);
	obj.close();
	if(intermediate.is_open())
	{       

		while (getline(intermedaiate, line))
		{	if(line.compare("")==0){
				//fstream pgml;
				//pgml.open("program_length.txt",ios::out);
				
				//PGMLENGTH=LOCCTR-STARTADRESS;
				//stringstream ss5;
				//ss5<< hex << PGMLENGTH; 
				//string res_pgmlength ( ss5.str() );
				//cout<<"\n program length"<<res_pgmlength<<endl;
				//pgml<<res_pgmlength<<endl;
				//pgml.close();
				break;
				}
			lineno++;
			cout<<"Assembling the instruction:"<<lineno<<":"<<line<<endl;
			//cout<<"line no"<<lineno;
			//cout<<line<<endl;
			if(line.at(0)=='.')
				continue;
    			stringstream ss(line);
    	
    			if(ss >> loc >> opcode >> operand)
    			{
				;
		
			}
			/*else{
				intermediate.seekg(-1*line.length(),ios::cur);
				getline(intermediate,line);
				stringstream ss(line);
				opcode="";operand="";
				ss>>opcode>>operand;
				loc="";
					//cout<<"here";
				
				//else{
					cout<<"here"<<endl<<endl;
					source.seekg(-1*(line.length()),ios::cur);
					getline(source,line);
					stringstream ss2(line);
					ss2>>opcode
						label="";operand="";
					

				//}

			}*/
			
			//cout<<"label:"<<label<<"opcode:"<<opcode<<"operand:"<<operand<<endl;
			int p=pass2(lineno,loc,opcode,operand,argv[1]);
			if(p==0){//update_block_table();
			 break;}
		//	cout<<"hello";
			//for(int i=0;i<block_sz;i++)
                        //	cout<<PGBLOCK[i]<<"\t"<<PGBLOCK[i]<<"\t"<<PGBLOCK[i]<<"\t"<<PGBLOCK[i]<<endl;

			//update_block_table();
			

    		
		}

		intermediate.close();
		
		
	}
	else cout<<"unable to open source file";
	
	
	return 0;




