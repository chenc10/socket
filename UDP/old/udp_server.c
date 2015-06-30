#define BUFFERSIZE 4096 
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>

int main(void){
	int UdpServerSocket;
	UdpServerSocket = socket(PF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in UdpServerAddr;
	struct sockaddr_in UdpClientAddr;
	bzero(&UdpServerAddr, sizeof(UdpServerAddr));
	UdpServerAddr.sin_family = AF_INET;
	UdpServerAddr.sin_port = htons(1234);
	UdpServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	extern int errno;
	bind(UdpServerSocket, (struct sockaddr *)&UdpServerAddr, sizeof(struct sockaddr_in));
	char Buffer[BUFFERSIZE];
	printf("begin to accept:\n");
	while(1){
		bzero(Buffer, sizeof(Buffer));
		int n;
	int len = sizeof(UdpServerAddr);
	n=recvfrom(UdpServerSocket,Buffer,BUFFERSIZE, 0, (struct sockaddr *)&UdpClientAddr, &len); 
	printf("finish! And the content is: %s \n", Buffer);
	//strcpy(Buffer,"Got it!");
//		const char * m = "haha thank you";
//
		if( sendto(UdpServerSocket, Buffer, n, 0, (struct sockaddr *)&UdpClientAddr, len) < 0)
			printf("errno: %d\n", errno);
	}
	close(UdpServerSocket);
	return 0;
}
