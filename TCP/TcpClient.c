#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define BUFFERSIZE 1000

int main(int argc, char *argv[]){
	int TcpClientSocket;
	TcpClientSocket = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in TcpServerAddr;
	const char * IP = "127.0.0.1";
	TcpServerAddr.sin_family = AF_INET;
	TcpServerAddr.sin_port = htons(1234);
	TcpServerAddr.sin_addr.s_addr = inet_addr(IP);

	if(connect(TcpClientSocket, (struct sockaddr *)&TcpServerAddr, sizeof(TcpServerAddr)) == -1){
		fprintf(stderr,"error connect\n");
		exit(-1);
	}
	char Buffer[BUFFERSIZE];
	strcpy(Buffer, "This is Chen by Tcp\n");
	send(TcpClientSocket, Buffer,strlen(Buffer), 0);
	recv(TcpClientSocket, Buffer,BUFFERSIZE, 0);
	printf("get response from server:%s\n", Buffer);
	close(TcpClientSocket);
	return 0;
}


