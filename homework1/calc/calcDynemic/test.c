#include <stdlib.h>
#include <dirent.h>
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
int main(){
DIR *dir;
struct dirent *entry;

dir=opendir("Plagins");

	if(!dir){
	perror("failure diropen");
	exit(1);
		};
	char name[64];
while((entry=readdir(dir))!=NULL)
	printf("%s\n",entry->d_name);

}
