#define BUFFERSIZE 4096
#include<sys/types.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
int main(void){
	int UdpClientSocket;
	struct sockaddr_in UdpServerAddr;
	int len;
	char Buffer[BUFFERSIZE];

	UdpClientSocket = socket(PF_INET,SOCK_DGRAM,0);

	bzero(&UdpServerAddr, sizeof(struct sockaddr_in));
	UdpServerAddr.sin_family = AF_INET;
	UdpServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	UdpServerAddr.sin_port = htons(1234);

	strcpy(Buffer,"Thisdfsafasfasdfasfasfsadsfafads is Chen!");
	sendto(UdpClientSocket,(const void *)Buffer, strlen(Buffer), 0, (struct sockaddr *) &UdpServerAddr, sizeof(struct sockaddr_in));
	recvfrom(UdpClientSocket, (void *)Buffer, BUFFERSIZE, 0,NULL, NULL);
	printf("Get reply from server: %s\n", Buffer);
	close(UdpClientSocket);
	return 0;
}

	

	
	



