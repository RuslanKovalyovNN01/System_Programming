#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MESSAGE_LENGTH 1024
#define PORT 8888
#define SA struct sockaddr 
int socket_file_descriptor, connection;
struct sockaddr_in serveraddress, client;
char message[MESSAGE_LENGTH];

int main(){
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_file_descriptor == -1){
        printf("Creation of socket failed.\n");
        exit(1);
    }
    bzero(&serveraddress, sizeof(serveraddress));
    serveraddress.sin_addr.s_addr = intet_addr("127.0.0.1");
    serveraddress.sin_port = htons(PORT);
    serveraddress.sin_family = AF_INET;
    connection = connect(socket_file_descriptor, (SA*)&serveraddress, sizeof(serveraddress));
    if(connection == -1){
        printf("Connection with the server failed.\n");
        exit(1);
    }
    while(1){
        bzero(message, sizeof(message));
        printf("Enter the message you want to send to server: \n");
        scanf("%[^\n]%*c", message);
        if((strncmp(message, "end", 3)) == 0){
            write(socket_file_descriptor, message , sizeof(message));
            printf("Client Exit.\n");
            break;
        }
        ssize_t bytes = write(socket_file_descriptor, message, sizeof(message));
        if(bytes >= 0){
            printf("Data send to the server successfuly.\n");
        }
        bzero(message , sizeof(message));
        read(socket_file_descriptor, message , sizeof(message));
        printf("Data received from server: %s\n", message);
    }
    close(socket_file_descriptor);
    return 0;
}