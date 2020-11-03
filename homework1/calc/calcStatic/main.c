#include <stdio.h>
#include <stdbool.h>
#include "deduction.h"
#include "multiplication.h"
#include "addition.h"
#include "segmentation.h"
void main(){
int a;
int b;
bool state_work=true;
float c;
int index;
printf("Press two numbers\n");
printf("\n");
	while(state_work){
	scanf("%d",&a);
	scanf("%d",&b);
	printf("Choose an operation\n");
	scanf("%d",&index);
	printf("\n");
	switch(index){
	case 1:
		sum(a,b,&c);
		printf("sum %f\n",c);
		break;
	case 2:
		ded(a,b,&c);
		printf("%f\n",c);
		break;
	case 3:
		multi(a,b,&c);
		printf("multiplay %f\n",c);
		break;
	case 4:
		segment(a,b,&c);
		printf("%f\n",c);
		break;
	default:
		printf("Please, choose an operation\n");
		state_work=false;
		break;
		}
	}
}

