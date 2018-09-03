#include"singlelevel.c"
#include"twolevel.c"
#include"hierarchical.c"

int main(){
	int c=-1;
	while(c!=4){
		printf("\n 1.Single level 2.Two level 3.Hierarchy 4.EXIT");
		scanf("%d",&c);
		if(c==1)
			singlelevel();
		else if(c==2)
			twolevel();
		else if(c==3)
			hierarchy();
		else;
	}
}
