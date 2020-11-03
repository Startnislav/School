#include <stdio.h>
#define N 5
int main(){
	int Triangular[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
				if (j>=i){
				Triangular[i][j]=1;
				}
			 	else{
				Triangular[i][j]=0;
				}
			}
		}	
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%d ",Triangular[i][j]);
			}
			printf("\n");
		}
}

