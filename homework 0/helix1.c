#include <stdio.h>
#define N 5

int main(){
	int helix[N][N];
	int k=0;
	int n=N;
	int row=0;
	while(n>=row){
		if(k<4*(n-1)){
			for(int i=row;i<n;i++){
				for(int j=row;j<n;j++){
				while(i==row){
					for(int f=row;f<n;f++){
						k++;
						helix[i][f]=k;
						}
					}
				while(j==n-1){
						for(int g=row;g<n;g++){
						k++;
						helix[g][j]=k;
						}
					}
				while(i==n-1){
						for(int f=n;f>row;f--){
						k++;
						helix[i][f]=k;
						}
					}
				while(j==row){
						for(int g=n;g>row;g--){
						k++;
						helix[g][j]=k;
						}
					}
				}
			}
		}
		else
		{
		k++;
		row++;
		n--;
		}
}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",helix[i][j]);
		}
		printf("\n");
	}
}
