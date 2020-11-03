#include<stdio.h>                                                                                             
#include<stdlib.h>                                                                                            
#include<string.h>                                                                                            
#include<sys/types.h>                                                                                         
#include<sys/socket.h>                                                                                        
#include<netinet/in.h>
#include<unistd.h>
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
	                                                                                                             
	// получаем данные  с сервера                                                                              
	char server_response[256];                                                                                   
	recv(network_socket, &server_response, sizeof(server_response), 0);                                          
	printf("The server sent the data: %s\n", server_response);                                                   
	close(network_socket);                                                                                       
	return 0;                                                                                                    
}                                   