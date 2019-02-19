#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define READ_SIZE 1024
#define HTTP_SIZE 2048

#define SERVER_PORT 80

// Client specifies in the command line what server to connect to
int main(int argc, char *argv[])
{
    // The client need to request and recive data when using HTTP
    char *address;
    address = argv[1];

    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // connet  to adress
    struct sockaddr_in remote_adress;
    remote_adress.sin_family = AF_INET;
    // Most webservers are on port 80
    remote_adress.sin_port = htons(SERVER_PORT);
    // Read in address specified from command line and convert it an address structure
    // This time we dont specify any IP address, but rather the one read from the command line
    inet_aton(address, &remote_adress.sin_addr.s_addr);

    // Connect to specified address
    connect(client_socket, (struct sockaddr*) &remote_adress, sizeof(remote_adress));

    // create string to hold request and request
    // request in the root on the server
    // Have several things to send requests for: EX: UPDATE
    char request[] = "GET / HTTP/1.1\r\n\r\n";
    char response[4096];

    // send to server
    send(client_socket, request, sizeof(request), 0);

    // recive responce
    recv(client_socket, &response, sizeof(response), 0);

    // print response to the console
    printf("response from server: %s\n", response);

    // close socket
    close(client_socket);



    return 0;
}
