#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<unistd.h>
#include<errno.h>
#include<netinet/in.h>
int main(int argc,char argv[]){
char server_msg[128]="adsaadwasxasdd";
int server_socket =socket(AF_INET,SOCK_STREAM,0);//создание сокета сервера
if(server_socket<0){
	perror("error initilization server_socket");
	return 0;
}
struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(9001);
server_address.sin_addr.s_addr=htonl(INADDR_ANY);

bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address));// присвоение адреса сокету
if(bind<0){
perror("error is bind");
exit(EXIT_FAILURE);
}
listen(server_socket,5);
if(listen<0){
perror("error is listen");
exit(EXIT_FAILURE);
}
int client_socket;
client_socket=accept(server_socket,NULL,NULL);
if(client_socket<0){
perror("error is accept");
exit(EXIT_FAILURE);
}
send(client_socket,server_msg,sizeof(server_msg),0);// отправляем сообщение
if(send<0){
perror("error is send");
exit(EXIT_FAILURE);
}
close(server_socket);
return 0;
}


