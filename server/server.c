#include "../include/socketutils.h"
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 8080 

int main(void) {

	int serverSocketFD = createTCPIpv4Socket();

	char* ip = "127.0.0.1";

	struct sockaddr_in* serverAddress = createIPv4Address(ip, PORT);

	int result = bind(serverSocketFD, (struct sockaddr *)serverAddress, sizeof(*serverAddress));

	if (result == 0) {
		printf("socket was bound successfully \n");
	}

	int listenResult = listen(serverSocketFD, 2);

	struct sockaddr_in clientAddress;
	socklen_t clientAddressSize = sizeof(struct sockaddr_in);
	int clientSocketFD = accept(serverSocketFD, (struct sockaddr *)&clientAddress, &clientAddressSize);

	char buffer[1024];
	recv(clientSocketFD, buffer, 1024, 0);

	printf("Response was: %s\n", buffer);

	return 0;
}
