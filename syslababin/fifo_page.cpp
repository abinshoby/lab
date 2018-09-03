// C++ implementation of FIFO page replacement
// in Operating Systems.
#include<bits/stdc++.h>

using namespace std;
 
// Function to find page faults using FIFO
// unordered_set<int> s;
int find_f(int pgno,int queue[20],int noq){
	for(int i=0;i<noq;i++){
		if(queue[i]==pgno)
			return 1;
	}
	return -1;
}
int pageFaults(int pages[], int n, int capacity)
{
   
        
    int queue[capacity];
    int noq=0;
    int fault=0;
    int first_used=0;
    for(int i=0;i<n;i++){
    	int res=find_f(pages[i],queue,noq);
    	if(res==-1){
    		fault++;
    		if(noq==capacity){
    			queue[first_used]=pages[i];
    			first_used=(first_used+1)%capacity;
    			
    			
    		}
    		else{
    			queue[noq++]=pages[i];
    		}
    		
    	}
    }
		
 
    return fault;
}
 
// Driver code
int fifo()
{ int n ;
int capacity;
    int pages[20] ;// //{7, 0, 1, 2, 0, 3, 0, 4,2, 3, 0, 3, 2};
cout<<"Enter the length of input string";
cin>>n;
cout<<"\n Enter the input string";
for(int i=0;i<n;i++)
	cin>>pages[i];
cout<<"\n enter capacity of a frame";
cin>>capacity;
   //= sizeof(pages)/sizeof(pages[0]);
     //= 4;
    cout <<"page faults:"<< pageFaults(pages, n, capacity);
    return 0;
}	
