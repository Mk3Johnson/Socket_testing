#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define PORT_NR 9002

int main()
{   
    // create string to send to server
    char server_message[256] = "You have made contact with the server\n";

    // create server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define socket adress
    struct sockaddr_in server_adress;
    server_adress.sin_family = AF_INET;
    server_adress.sin_port = htons(PORT_NR);       // Connect to the same port
    server_adress.sin_addr.s_addr = INADDR_ANY; // Choose any adress (IP)

    // bind socket to specified IP and port
    bind(server_socket, (struct sockaddr*) &server_adress, sizeof(server_adress));

    // listen to connection
    // The second argument is for how many backlogs we want to have. 
    // If only one connection, only needs to have a number greater or equal to 1
    listen(server_socket, 5);

    // Listen to connection, when we connect, we accept the result and can then interprite and handle that data
    int client_socket;
    // Can bothe send() and recv(). 
    // First arg = socket for sending, "server_socket"
    // Second arg = structure for client connection, socket adress and IP and so on
    // Third arg = 
    client_socket = accept(server_socket, NULL, NULL);

    // send message: To, From, How large
    send(client_socket, &server_socket, sizeof(server_message), 0);

    // close connection
    close(server_socket);

    return 0;
}