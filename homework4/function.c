#include"function.h"
#include<string.h>
#include<dirent.h>
void *print_dir(void *arg){
DIR *fd;
struct dirent **entry;
char buff[128]="./";
int x, y;
int n=0;
WINDOW *win = (WINDOW*) arg;
wclear(win);
box(win,0,0);
wrefresh(win);
x=1;
y=2;
n=scandir(".",&entry,0,alphasort);
if(n==-1){
	perror("scandir");
}
else{
	while(n--){
			char *ptr=calloc(strlen(entry[n]->d_name),sizeof(char));
			strcpy(ptr,entry[n]->d_name);
			mvwaddstr(win,x,y,ptr);
			free(ptr);
			free(entry[n]);	
			y++;
	}

}

x=1;
y=2;
wmove(win,y,x);
closedir(fd);
wrefresh(win);
}
