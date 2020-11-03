#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>
#include"Function.h"
#define ONE 1
void main(){
struct person *list;
int deleteNumber;
int NumberPerson;
int quantatyPerson=ONE;
char operate;
list=(struct person * )malloc(ONE*sizeof(struct person));
if(sizeof(list)!=NULL){
bool still_work=true;
}
printf("------------\n1-add person\n2-view book\n3-delete person\n4-print person\n5-print book----------");
while(still_work){
operate=getchar();
 switch(operate){
 		case '1':
			printf("please, add person\n");
			add_person(list, &quantatyPerson);
 			break;
		case '2':
			printf("please, view persons\n");
			view_quantaty(list, &quantatyPerson);
			break;
		case '3':
			printf("Delete person \n");
			printf("press number\t");
			scanf("%d", &deleteNumber);
			delete_person(list,deleteNumber,&quantatyPerson);
		        break;
		case '4':
			printf("Number person\n ");
			printf("press number\t");
			scanf("%d", &NumberPerson);
			view_person(list,NumberPerson,&quantatyPerson);
			break;
		case '5':
			print(list,&quantatyPerson);
			break;

		default:
			free(list);
			printf("Exit");
 			still_work=false;
			break;
 		}
	

}
}
