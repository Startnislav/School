#include <stdio.h>

int main(){
unsigned int number=0x00ccbbaa;
//printf("%d",number);

for(int i=0;i<4;i++){
	int shift=i*8;
	int totalShift;
	totalShift=number>>shift;
	int g=0x000000ff;
	int total=totalShift & g;
	printf("%d element by bit %d \n",i,total);
	}
}
