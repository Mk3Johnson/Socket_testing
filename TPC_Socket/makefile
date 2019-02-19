CC = gcc
CLFAGS = -w -o

all: TCPClient TCPServer

TCPClient: socket_client.c
	$(CC) $(CLFAGS) TCPClient socket_client.c 

TCPServer: socket_server.c 
	$(CC) $(CLFAGS) TCPServer socket_server.c 

