#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(){
int double_array[N][N];
for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
			double_array[i][j]=rand()%(N*N);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
				printf("%d ", double_array[i][j]);
			}
		printf("\n");
}


}
