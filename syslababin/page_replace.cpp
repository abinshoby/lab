#include"fifo_page.cpp"
#include"lrupage.c"
#include"lfu_page.c"

int main(){
	int c=-1;
	while(c!=4){
		printf("\n 1.FIFO 2.LRU 3.LFU 4.EXIT");
		scanf("%d",&c);
		if(c==1)
			fifo();
		else if(c==2)
			lru();
		else if(c==3)
			lfu_call();
		else;
	}
}
