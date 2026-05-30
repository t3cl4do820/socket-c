#include "../include/socketutils.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080

int main(void) {
	int socketfd = createTCPIpv4Socket();
	
	char* ip = "127.0.0.1";

	struct sockaddr_in* address = createIPv4Address(ip, PORT);

	int connectStatus = connect(socketfd, (struct sockaddr *)address, sizeof(*address));

	if (connectStatus == 0) {
		printf("connection was successful \n");
	}

	char* line = NULL;
	size_t lineSize = 0; // initial value

	printf("commands: exit -> to exit\n");
	printf("write your message: \n");
	while (1) {	
		ssize_t charCount = getline(&line, &lineSize, stdin);

		if (charCount > 0) {
			if (strcmp(line, "exit\n") == 0) {
				break;
			}

			ssize_t amountWasSend = send(socketfd, line, charCount, 0);

		}

	}

	close(socketfd);

	return 0;
}
