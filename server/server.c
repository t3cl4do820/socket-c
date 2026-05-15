// if u have any problem, just do: man <lib or binary>
#include <stdio.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void) {

	int socketfd =  socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addres = {
		.sin_family = AF_INET,
		.sin_port = htons(8000),
		.sin_addr = 0 // for local conection
	};

	bind(socketfd, (struct sockaddr *)&addres, sizeof(addres));
	listen(socketfd, 5);

	socklen_t size = sizeof(addres);

	int clientfd = accept(socketfd, (struct sockaddr *)&addres, &size);

	if (clientfd == -1) {
		printf("Not client connected! \n");
		return -1;
	}
		
	struct pollfd fds[2] = {
		{0, POLLIN, 0},
		{clientfd, POLLIN, 0}
	};

	for (;;) {

		poll(fds, 2, 50000);

		char buffer[257];

		if (fds[0].revents & POLLIN) {
			read(0, buffer, 255);
			send(clientfd, buffer, 255, 0);
		} else if (fds[1].revents & POLLIN) {
			recv(clientfd, buffer, 255, 0);
			printf("%s \n", buffer);
		}
	}	

	return 0;
}
