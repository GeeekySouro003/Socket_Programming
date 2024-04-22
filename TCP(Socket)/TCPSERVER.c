#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define PORT_NUM 2500

int main() {
    int server_socketid, client_socketid, server_len, client_len;
    char out_buf[100];
    char in_buf[100];
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    // Creating socket
    server_socketid = socket(AF_INET, SOCK_STREAM, 0);

    // Naming socket
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT_NUM);

    // Bind connection
    server_len = sizeof(server_address);
    bind(server_socketid, (struct sockaddr *)&server_address, server_len);

    // Listen connection
    listen(server_socketid, 5);

    printf("SERVER WAITING FOR CLIENT REQUEST....\n");

    while(1) {
        client_len = sizeof(client_address);



        // TCP Server Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client;
    socklen_t len = sizeof(struct sockaddr_in);

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error in socket creation\n");
        exit(1);
    }

    // Initialize server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    // Bind server socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Bind failed\n");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    printf("Waiting for incoming connections...\n");

    // Accept incoming connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client, &len);
        if (client_socket < 0) {
            printf("Server accept failed...\n");
            exit(0);
        } else {
            printf("Server accepted the client...\n");
        }

        // Communication with client
        char buffer[256];
        memset(buffer, 0, sizeof(buffer));
        read(client_socket, buffer, sizeof(buffer));
        printf("From Client: %s\n", buffer);
        write(client_socket, buffer, sizeof(buffer));

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);
    return 0;
}
