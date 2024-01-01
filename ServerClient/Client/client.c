#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

enum{
    PORT = 1488
};

#define SERVER_IP INADDR_LOOPBACK //"127.0.0.0"
#define MESSAGE "Henlo"

int main(int argc, char *argv[]){
    int socket_fd;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);

    int addr_is_valid = inet_aton(SERVER_IP, &(addr.sin_addr)); 
    if(!addr_is_valid){
        printf("Invalid server IP\n");
        return 1;
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1){
        //printf("Failed to connect to server\n");
        perror("socket");
        return 1;
    }


    int bind_res = bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
    if(bind_res == -1){
        perror("bind");
        //printf("Cannot bind socket\n");
        return 1;
    }

    int conection_res = connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
    if(conection_res == -1){
        printf("Failed to connect to server\n");
        return 1;
    }

    int write_res = write(socket_fd, (const void *)MESSAGE, sizeof(MESSAGE));
    if(write_res == -1){
        perror("write:");
        return 1;
    }

    close(socket_fd);


    return 0;
}