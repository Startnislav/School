#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<errno.h>
struct msgbuf{
long mtype;
char mtext[16];
};
void usage(char *prog_name,char *msg){
if(msg!=NULL)
	fputs(msg,stderr);
fprintf(stdout,"Usage: %s [options\n]",prog_name);
fprintf(stdout,"Options are:\n",prog_name);
fprintf(stdout,"-s send message using msgsnd",prog_name);
fprintf(stdout,"-r read message using msgrcv",prog_name);
fprintf(stdout,"-t message type",prog_name);

}

void send_msg(int qid,int msgtype){
struct msgbuf msg;
msg.mtype =msgtype;
if(msgsnd(qid,(void*)&msg,sizeof(msg.mtext),IPC_NOWAIT)==-1){
perror("msg error");
exit(EXIT_FAILURE);
}
printf("sent: %s\n",msg.mtext);
}

void get_msg(int qid,int msgtype){
struct msgbuf msg;
if(msgrcv(qid,(void*)&msg,sizeof(msg.mtext),msgtype,MSG_NOERROR|IPC_NOWAIT)==-1){
perror("rcv error");
exit(EXIT_FAILURE);


printf("No message available for msgrcv()\n");
}
else{
printf("message received: %s\n",msg.mtext);
}
}
int main(int argc,char *argv[]){
int qid, opt;
key_t msgkey;
int mode=0;
int msgtype=1;
msgkey=ftok("/tmp",'A');
qid=msgget(msgkey,IPC_CREAT|0666);
if (qid ==-1){
	perror("msgget error");
	exit(EXIT_FAILURE);

}
while((opt=getopt(argc,argv,"srt:k:"))!=-1){
switch(opt){
	case 's':
		mode=1;
		send_msg(qid,msgtype);
		break;
	case 'r':
		mode=2;
		get_msg(qid,msgtype);
		break;
	case 't':
		msgtype=atoi(optarg);
		break;
	default:
		usage(argv[0],"unrecognized option\n");
		break;

}	


}


}
