#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char const *argv[]){
DIR *dir;
struct dirent *entry;

	dir=opendir("Plagins");
	if(!dir){
		perror("diropen");
		exit(1);
		};
	char name_lib[64];
	//int number=0;
	
	strcpy(name_lib,"Plagins/");
	while(( entry=readdir(dir))!=NULL){
		if(!(entry->d_name[0]=='.'))	
		strcat(name_lib,entry->d_name);
	//printf("%s",name_lib);
	//number++;
	};
//	for(int i=0;i<number;i++){
	void *ptr_lib;
	ptr_lib=dlopen(name_lib,RTLD_LAZY);
	if(!ptr_lib){
			fprintf(stderr,"dlopen failure:%s\n",dlerror());
			exit(EXIT_FAILURE);
			};
//	}
closedir(dir);
float a;
float b;
float c;
void (*undefined_func)(float a,float b,float *c);
bool state_work=true;
int index;
	while(state_work){
	printf("Press first number\n");
	scanf("%f",&a);
	printf("\n");
	printf("Press second number\n");
	scanf("%f",&b);
	printf("\n");
	printf("Choose an operation\n");
	scanf("%d",&index);
	printf("\n");	
	switch(index){
	case 1:
		undefined_func=dlsym(ptr_lib,"sum");
		undefined_func(a,b,&c);
		printf("%f\n",c);
		break;
	case 2:
		undefined_func=dlsym(ptr_lib,"ded");
		undefined_func(a,b,&c);
		printf("%f\n",c);
		break;
	case 3:
		undefined_func=dlsym(ptr_lib,"multi");
		undefined_func(a,b,&c);
		printf("%f\n",c);
		break;
	case 4:
		undefined_func=dlsym(ptr_lib,"segment");
		undefined_func(a,b,&c);
		printf("%f\n",c);
	default:
		printf("Please, choose an operation\n");
		state_work=false;
		break;
		}
	}
dlclose(ptr_lib);
}

