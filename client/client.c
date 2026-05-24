#include "../include/socketutils.h"
#include <stdio.h>
#include <string.h>

#define PORT 8080

int main(void) {
	int socketfd = createTCPIpv4Socket();
	
	char* ip = "127.0.0.1";

	struct sockaddr_in* address = createIPv4Address(ip, PORT);

	int result = connect(socketfd, (struct sockaddr *)address, sizeof(*address));

	if (result == 0) {
		printf("connection was successful \n");
	}

	char* message;
	message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
	send(socketfd, message, strlen(message), 0);

	char buffer[1024];
	recv(socketfd, buffer, 1024, 0);

	printf("Response was: %s\n", buffer);
	
	return 0;
}
