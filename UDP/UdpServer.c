#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

#define BUFFERSIZE 1000

int main(int argc, char *argv[]){
	int UdpServerSocket;
	UdpServerSocket = socket(AF_INET,SOCK_DGRAM, 0);

	struct sockaddr_in UdpServerAddr, UdpClientAddr;
	bzero(&UdpServerAddr, sizeof(UdpServerAddr));

	UdpServerAddr.sin_family = AF_INET;
	UdpServerAddr.sin_port = htons(1234);
	UdpServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(UdpServerSocket, (struct sockaddr *)&UdpServerAddr, sizeof(UdpServerAddr));

	int addrlen = sizeof(UdpClientAddr);
	char Buffer[BUFFERSIZE];
	bzero(Buffer, BUFFERSIZE);
	time_t ComTime;
	while(1){
		recvfrom(UdpServerSocket,Buffer,BUFFERSIZE, 0, (struct sockaddr *)&UdpClientAddr, &addrlen);
		time(&ComTime);
		printf("Get input At %s  %s\n", ctime(&ComTime), Buffer);
		sendto(UdpServerSocket, Buffer, strlen(Buffer), 0, (struct sockaddr *)&UdpClientAddr, addrlen);
		printf("Finish one loop\n");
	}
	close(UdpServerSocket);
	return 0;
}


