#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define READ_SIZE 1024
#define HTTP_SIZE 2048

#define PORT_NR 8001

int main()
{
    /* open the file to serve it to client */

    // Change when reading and writing data
    // Need to rad and write html 
    FILE *html_data;
    // The server will serve this html page to the client. w = write, r = read
    html_data = fopen("index.html", "r");

    char response_data[READ_SIZE];
    // Read the data from html_data and store to response
    fgets(response_data, READ_SIZE, html_data);

    // Response header for the data 
    char http_header[HTTP_SIZE] = "HTTP/1.1 200 OK\r\n\n";

    // Responce body is the main html page, we send both header and body concatinated to the client
    strcat(http_header, response_data);



    /* Create a connection */
    // Create socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NR);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    // bind the socket to a port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket,5);

    int client_socket;

    // Always listen for requests and be able to send responces
    while (true)
    {
        // Only responds to requests. Serves http_header to client
        client_socket = accept(server_socket, NULL, NULL);
        send(client_socket, http_header, sizeof(http_header), 0);
        close(client_socket);


    }

    return 0;
}
