#include<pthread.h>
#include<stdio.h>
#include<curses.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<signal.h>
#include<termios.h>
#include<stdlib.h>
#include<dirent.h>
#include"function.h"
#define BUFF_SIZE 256
#define START_POINT_X 0
#define START_POINT_Y 0
#define NUM_WINDOW 2
struct winsize size;
void sig_winch(int signo){
ioctl(fileno(stdout),TIOCGWINSZ,(char *)&size);
resizeterm(size.ws_row,size.ws_col);
}
int main(int argc, char *argv[]){
	bool still_work;
	int  handle_file=-1, key_command, x=0, y=0; 
char buff[BUFF_SIZE]="./";
struct dirent **entry_windowR;
struct dirent **entry_windowL;
DIR *dir;
FILE *file;
initscr();
signal(SIGWINCH,sig_winch);
ioctl(fileno(stdout),TIOCGWINSZ,(char *)&size);
WINDOW **window_buff=calloc(1,sizeof(WINDOW));//указатель на указатель структур WINDOW(всего 2 структуры)
WINDOW *windowR=newwin(size.ws_row,size.ws_col/2,START_POINT_Y,size.ws_col/2);//1 структура
box(windowR,0,0);
mvwaddstr(windowR,1,size.ws_col/4,"RIGHT LIST");
wrefresh(windowR);
WINDOW *windowL=newwin(size.ws_row,size.ws_col/2,START_POINT_Y,START_POINT_X);// 2 структура
box(windowL,0,0);
mvwaddstr(windowL,1,size.ws_col/4,"LEFT LIST");
wrefresh(windowL);
start_color();
keypad(stdscr,true);
keypad(windowL,true);
keypad(windowR,true);
cbreak();
echo();
curs_set(1);
init_pair(1,COLOR_YELLOW,COLOR_BLUE);
init_pair(2,COLOR_GREEN,COLOR_BLUE);
attron(A_BOLD);
wattron(windowR,COLOR_PAIR(1));
wattron(windowL,COLOR_PAIR(1));
wbkgd(windowR,COLOR_PAIR(2));
wbkgd(windowL,COLOR_PAIR(2));
wrefresh(windowR);
int i=0;
window_buff=&windowL;
while(1){
pthread_t thread;
pthread_create(&thread,NULL, print_dir, (WINDOW *)window_buff[i]);
key_command=wgetch(*window_buff);
switch(key_command){
	case KEY_UP:
		getyx(*window_buff,y,x);
		if(y-1<0){
		wmove(*window_buff,y,x);	
		}
		else{
		wmove(*window_buff,y-1,x);
		}
		wrefresh(*window_buff);
		break;
	case KEY_DOWN:
		getyx(*window_buff,y,x);
		if(y+1>size.ws_row){
		wmove(*window_buff,y,x);	
		}
		else{
		wmove(*window_buff,y+1,x);
		}
		wrefresh(*window_buff);
		break;
	case KEY_F(1):
		pthread_join(thread,NULL);	
		if(*window_buff==windowL){
			window_buff=&windowR;
		}
		else{
			window_buff=&windowL;
			}
		break;
}

}


}
