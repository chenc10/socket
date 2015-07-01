#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>

#define BUFFERSIZE 1000
int main(int argc, char *argv[]){
	int TcpServerSocket, TmpTcpServerSocket;
	TcpServerSocket = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in TcpServerAddr, TcpClientAddr;
	int addrlen = sizeof(TcpClientAddr);
	bzero(&TcpServerAddr, sizeof(TcpServerAddr));
	TcpServerAddr.sin_family = AF_INET;
	TcpServerAddr.sin_port = htons(1234);
	TcpServerAddr.sin_addr.s_addr = htons(INADDR_ANY);

	bind(TcpServerSocket, (struct sockaddr *)&TcpServerAddr, sizeof(TcpServerAddr));

	listen(TcpServerSocket, 20);
	char Buffer[BUFFERSIZE];
	while(1){
		TmpTcpServerSocket = accept(TcpServerSocket, (struct sockaddr *)&TcpClientAddr, &addrlen); 
		recv(TmpTcpServerSocket, Buffer, BUFFERSIZE, 0);
		printf("get input: %s\n", Buffer);
		send(TmpTcpServerSocket, Buffer, strlen(Buffer), 0);
		close(TmpTcpServerSocket);
	}
	close(TcpServerSocket);
	return 0;
}
