#include<stdio.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<signal.h>
#include<stdlib.h>
#include<termios.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<unistd.h>
#include<curses.h>	
struct winsize size;
void sig_winch(int signo){
ioctl(fileno(stdout),TIOCGWINSZ,(char *)&size);
resizeterm(size.ws_row, size.ws_col);
	}
int main(int argn,char *argv[]){
WINDOW *wnd;
FILE *File;
int fd=-1;
int x,y,mx,my;
char rw_buf[128];
void *rw_ptr=&rw_buf;

if((fd=open("test",O_RDWR))==-1){
	perror("not open");
	exit(1);
}
File=fdopen(fd,"r+");
initscr();
signal(SIGWINCH,sig_winch);
ioctl(fileno(stdout),TIOCGWINSZ, (char *) &size);
curs_set(1);
start_color();
init_pair(1,COLOR_WHITE,COLOR_GREEN);
init_pair(2,COLOR_WHITE,COLOR_BLACK);

attron(COLOR_PAIR(1));
bkgd(COLOR_PAIR(1));
printw("F2-close");
for(int i=1;i<size.ws_row-1;i++){

mvprintw(i,0,"%d",i);
}
wnd=newwin(size.ws_row-4,size.ws_col-4,1,2);
wattron(wnd,COLOR_PAIR(2));
getmaxyx(wnd, my,mx);
raw();
noecho();
refresh();
wrefresh(wnd);
wmove(wnd,0,0);
while(read(fd,rw_buf,1)>0){
wprintw(wnd,rw_buf);
}
keypad(wnd,true);
wrefresh(wnd);
bool work=true;
while (work){
	int symbol=wgetch(wnd);
	switch(symbol){
		case KEY_LEFT:
			getyx(wnd,y,x);
			if((x-1)<=0){
			wmove(wnd,y-1,mx);
			}
			else{
			wmove(wnd,y,x-1);
			}
			break;
		case KEY_RIGHT:
			getyx(wnd,y,x);
			if((x+1)>mx){
			wmove(wnd,y-1,0);
			}
			else{
			wmove(wnd,y,x+1);
			}	
			break;
		case KEY_UP:
			getyx(wnd,y,x);
			if((y-1)>=0){
			wmove(wnd,y-1,x);
			}
			else{
			wmove(wnd,0,x);
			}
			break;
		case KEY_DOWN:
			getyx(wnd,y,x);
			if((y+1)>my){
			wmove(wnd,my,x);
			}
			else{
			wmove(wnd,y+1,x);
			}
			break;
		case KEY_ENTER:
			getyx(wnd,y,x);
			mvwgetstr(wnd,y,x,rw_buf);
			mvaddstr(y+1,0,rw_buf);	
			wclrtoeol(wnd);	
			wmove(wnd,y+1,0);
			break;	
		case KEY_F(2):
			endwin();
			if(fclose(File)==-1){
				perror("Not close file");
			}
			work=false;
			break;
		case KEY_BACKSPACE:
			getyx(wnd,y,x);
			if((x-1)<0){
			wmove(wnd,y-1,mx);
			wrefresh(wnd);
			getyx(wnd,y,x);
			mvwdelch(wnd,y,x);
			break;
			}
			mvwdelch(wnd,y,x);
			wmove(wnd,y,x-1);
			break;
		default:
			getyx(wnd,y,x);
			wechochar(wnd,(char)symbol);		
			break;
			
		}	
		wrefresh(wnd);
	}
}
