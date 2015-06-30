#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>

#define BUFFERSIZE 1000

int main(int argc, char *argv[]){
	int UdpServerSocket, UdpClientSocket;
	UdpClientSocket = socket(AF_INET,SOCK_DGRAM, 0); 

	struct sockaddr_in UdpServerAddr;
	bzero(&UdpServerAddr, sizeof(UdpServerAddr));
	const char * IP = "127.0.0.1";
	
	UdpServerAddr.sin_family = AF_INET;
	UdpServerAddr.sin_port = htons(1234);
	UdpServerAddr.sin_addr.s_addr = inet_addr(IP);

	char Buffer[BUFFERSIZE];
	strcpy(Buffer, "Hello world");
	sendto(UdpClientSocket, Buffer, strlen(Buffer), 0, (struct sockaddr *)&UdpServerAddr, sizeof(UdpServerAddr));
	recvfrom(UdpClientSocket, Buffer, BUFFERSIZE, 0, NULL, NULL);
        printf("Get response!\n");	
	return 0;
}

	
