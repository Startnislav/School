#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(){
	int  arr[5]={0,0,0,0,0};
	int k=0;
	int p=N-1;	
for(int i=0;i<N;i++){
	arr[i]=rand()%N;
}
	for(int i=0;i<N;i++){
	printf("%d  ",arr[i]);
}
	printf("\n");

	for(int i=0;i<=p/2;i++){
	k=arr[i];
	arr[i]=arr[p-i];
	arr[p-i]=k;	
	}
	for(int i=0;i<N;i++){
		printf("%d ",arr[i]);
	}

}
