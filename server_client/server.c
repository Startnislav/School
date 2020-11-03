#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<pthread.h>

#define NUM_OF_CLIENT 10
#define LENGTH_STRING 128
void *usage(void*ptr){
int *acceptor=(int *)ptr;
char *buff=calloc(LENGTH_STRING,sizeof(char));
while(1){
	int rc=0;
	rc=recv(*acceptor,buff,LENGTH_STRING,0);
	
	if(rc<0){
	perror("usage.recv is error");
	exit(EXIT_FAILURE);
	}
	
	if(!strncmp(buff,"!q",2))
		break;
	printf("%s",buff);
	rc=send(*acceptor,buff,LENGTH_STRING,0);
	if(rc<0){
	perror("usage.send is error");
	exit(EXIT_FAILURE);
	}
}
free(buff);
close(*acceptor);
}
int main(int argc,char *argv[]){
int num_client=0;
	
	int server_socket=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(9001);
	server_address.sin_addr.s_addr=htonl(INADDR_ANY);

	bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address));
	if(bind<0){
	perror("bind is error");
	exit(EXIT_FAILURE);
	}
	listen(server_socket,NUM_OF_CLIENT);

	if(listen<0){
	perror("listen is error");
	exit(EXIT_FAILURE);
	}
	int client_socket[NUM_OF_CLIENT];
	
	while(1){
	pthread_t pthread_client;
	client_socket[num_client]=accept(server_socket,NULL,NULL);
	if(client_socket[num_client]<0){
	perror("accept is error");
	exit(EXIT_FAILURE);
	}
	pthread_create(&pthread_client,NULL,usage,&client_socket[num_client]);
	num_client++;
	}	
	for(int i=0;i<num_client;i++)
	close(client_socket[i]);
	
	close(server_socket);
	return 0;

}

