#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

enum{
    PORT = 1488,
    BUF_SIZE = 100
};

#define CLIENT_IP INADDR_LOOPBACK //"127.0.0.0"


int main(int argc, char *argv[]){
    char buf[BUF_SIZE];
    int socket_fd;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);

    int addr_is_valid = inet_aton(CLIENT_IP, &(addr.sin_addr)); 
    if(!addr_is_valid){
        perror("inet_aton");
        //printf("Invalid server IP\n");
        return 1;
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1){
        perror("socket");
        return 1;
    }

    int bind_res = bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
    if(bind_res == -1){
        perror("bind");
        //printf("Cannot bind socket\n");
        return 1;
    }

    int listen_res = listen(socket_fd, 3);
    if(listen_res == -1){
        perror("listen");
        return 1;
    }

    socklen_t addr_len = sizeof(addr);
    int client_fd = accept(socket_fd, (struct sockaddr *)&addr, &addr_len);
    if(client_fd == -1){
        perror("accept");
        return 1;
    }

    int read_res = read(client_fd, buf, BUF_SIZE);
    if(read_res == -1){
        perror("read");
        return 1;
    }
    buf[BUF_SIZE - 1] = '\0';

    printf("%s\n", buf);

    close(socket_fd);
    close(client_fd);

    return 0;
}