#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define PORT_NR 9002

int main()
{
    // Create container for the socket
    int network_socket;
    // Since its an internet socket, we pass AF_INT.
    // We use TCP to send and confirm sending packets, so include SOCK_STREAM
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Socket now set up. Now we need to connect to another socket
    // sin_ is also a scructure holding information of the 
    // Specify adress for socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NR);   // Need to convert integer to a port number (data format)
    server_address.sin_addr.s_addr = INADDR_ANY; // Set any adress

    // Connect to the socket and type cast the adress
    // ret 0 = OK
    // ret -1 = Error
    int connect_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // Check for connection validation
    if(connect_status == -1)
    {
        printf("An error occured in the connection to the removte server!\n\n");
    }

    // Recive data from the server
    char server_response[256];   // Store responce from the reciver
    recv(network_socket, server_response, sizeof(server_response), 0);


    // Print out recived data
    printf("The server sent: %s\n\n", server_response);

    close(network_socket);

    return 0;
}