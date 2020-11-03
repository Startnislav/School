#include "Function.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

void add_person(struct person *list, int *quantatyPerson){
char *ptr;
*quantatyPerson = *quantatyPerson + 1;
list = realloc(list, (*quantatyPerson) * (sizeof(struct person)));
ptr=list[(*quantatyPerson)].name;
printf("press name\n");

while(*ptr!='\n'){*ptr++=getchar();}
*ptr='\0';

printf("press number\n");
scanf("%d",&list[(*quantatyPerson)].number);
}
void print(struct person *list, int *quantatyPerson){
for(int i=0;i<*quantatyPerson;i++){
	printf("Name\t",list[i].name);
	printf("Phone\t",list[i].number);

}

}
void view_person(struct person *list,int NumberPerson,int *quantatyPerson){
printf("\n---------------\n");
	char str[16];
	strcpy(str, list[NumberPerson].name);
	printf("name:\t");
	puts(str);
	printf("\n");
	printf("number: %d\n",list[NumberPerson].number);
	
}
void delete_person(struct person *list, int deleteNumber,int *quantatyPerson ){


	for (int i = (deleteNumber); i < (*quantatyPerson) - 1 ; i++)
	{
		
			list[i].number = list[i+1].number;
			strcpy(list[i].name, list[i+1].name);

	}
			*quantatyPerson = *quantatyPerson - 1;
			list = realloc(list, (*quantatyPerson) *( sizeof(struct person)));
}
	

void view_quantaty(struct person *list, int *quantatyPerson){

	for(int i=1;i<*quantatyPerson;i++){
		char str[16];
		strcpy(str,list[i].name);
		printf("name:\t");
		puts(str);
		printf("number: %d\n",list[i].number);
	
	}
}
