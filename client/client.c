#include <netinet/in.h>
#include <stdio.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <poll.h>
#include <unistd.h>

int main(void) {
	
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);	
	
	struct sockaddr_in address = {
		.sin_family = AF_INET,
		.sin_port = htons(8000),
		.sin_addr = 0 // localhost
	};

	if (connect(socketfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
		printf("falha na conexao! \n");
		return -1;
	}

	struct pollfd fds[2] = {
		{0, POLLIN, 0},
		{socketfd, POLLIN, 0}
	};
	
	for (;;) {
		poll(fds, 2, 50000);
		
		if (fds[0].revents & POLLIN) {
			char buffer[256];
			read(0, buffer, 255);
			send(socketfd, buffer, 255, 0);
		}

		if (fds[1].revents & POLLIN) {	
			char buffer[256];
			recv(socketfd, buffer, 255, 0);
			printf("%s\n", buffer);
		}
	}

	return 0;
}
