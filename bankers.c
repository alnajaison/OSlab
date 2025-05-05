//bankers algorithm
#include<stdio.h>

int i, j, k;
int isSafe(int np,int nr,int cw[5],int alloc[10][5],int maxm[10][5]){
	int need[10][5], finished[10]={0}, seq[10], work[5];
	for (i=0;i<np;i++){   //need matrix
    	   for (j=0;j<nr;j++){
        	      need[i][j]=maxm[i][j]-alloc[i][j];   
    	} }       	 
	for (i=0;i<nr;i++) {
    	   work[i]=cw[i];
	}
	
	int c=0,flag;
	while(c<np){
    	   flag=0;
    	   for(i=0;i<np;i++){
        	      if (!finished[i]) {
            	for (j=0;j<nr;j++) {
                	   if (need[i][j]>work[j]) {
                    	   break;}
            	}
            	if (j==nr) {
                	   for(k=0;k<nr;k++){
                    	      work[k]+=alloc[i][k];
                	   }
                	seq[c++]=i;
                	finished[i]=1;
                	flag=1;
            	} }
    	}
    	
	if (flag) {
	printf(" Safe State !!\nSequence: ");
	printf(" < ");
	for (i=0;i<np;i++) {
    	printf("P%d ", seq[i]);
	}
	printf(" > \n"); }
}

void  main(){
	int np, nr, cw[5],alloc[10][5],maxm[10][5];
	printf("Enter the number of Processes: ");
	scanf("%d", &np);
	printf("Enter the number of resources: ");
	scanf("%d", &nr);    
	printf("Enter the Current Work: \n");
	for (i=0;i<nr;i++){
    	scanf("%d", &cw[i]);	}
	printf("Enter the Allocated Resources: \n");
	for (i=0;i<np;i++){
    	for (j=0;j<nr;j++){
        	scanf("%d", &alloc[i][j]); 	}}
	printf("Enter the Maxm Resources: \n");
	for (i=0;i<np;i++){
    	for (j=0;j<nr;j++){
        	scanf("%d", &maxm[i][j]); 	}}
       	 
	isSafe(np,nr,cw,alloc,maxm);
}
