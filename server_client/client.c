#include<stdio.h>                                                                                             
#include<stdlib.h>                                                                                            
#include<string.h>                                                                                            
#include<sys/types.h>                                                                                         
#include<sys/socket.h>                                                                      
#include<netinet/in.h>

#include<unistd.h>

#define LENGTH_STRING 128


int main() {                                                                                                   
	                                                                                           
int network_socket=socket(AF_INET, SOCK_STREAM, 0); //создание сокета                                                           
	                                                                                                             
	struct sockaddr_in server_address;                                                                           
	server_address.sin_family = AF_INET;                                                                         
	server_address.sin_port = htons(9001);                                                                       
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);                                                                 
                                                                                                               
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));//соединяем сокет клиентас адресом сервера
	if (connection_status == -1){                                                                                
		printf("There was an error making a connection to the remote socket \n\n");                              
	}                                                                                                            
	                                                                                                             
while(1){
printf("!q for leave chat\n");
char *buff=calloc(LENGTH_STRING,sizeof(char));
fputs("\n ",stdout);
fgets(buff,LENGTH_STRING,stdin);
if(!strncmp(buff,"!q",2)){
int ss = send(network_socket,buff,LENGTH_STRING,0);
	if(ss<0){
	perror("send is error");
	exit(EXIT_FAILURE);
	}
free(buff);
break;
}
int ss=send(network_socket,buff,LENGTH_STRING,0);
	if(ss<0){
	perror("send is error");
	exit(EXIT_FAILURE);
	}
int rc=recv(network_socket,buff,LENGTH_STRING,0);
if(rc<0){
perror("recv is error");
exit(EXIT_FAILURE);
}
fputs(buff,stdout);
free(buff);
}
close(network_socket);
return 0;
}                                   
