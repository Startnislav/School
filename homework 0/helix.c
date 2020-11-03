#include <stdio.h>
#define N 3

int main(){
	int helix[N][N];
	int i=0;
	int j=0;
	int k=1;
	int n=N;
	int row=0;
while(k<=N*N){
			i=row;
				for( j=row;j<n;j++){
					helix[i][j]=k;
					k++;
					}
			 j=n-1;
				for(i=row+1;i<n;i++){
					helix[i][j]=k;
					k++;
					}
			 i=n-1;
				for(j=n-2;j>row;j--){
					helix[i][j]=k;
					k++;
					}
			 j=row;
				for(i=n-1;i>row;i--){
					helix[i][j]=k;
					k++;
					}
		row++;
		n--;
}
	//if(N%2)
	//helix[(N/2)+1][(N/2)+1]=N*N;	

for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",helix[i][j]);
		}
		printf("\n");
	}
}
