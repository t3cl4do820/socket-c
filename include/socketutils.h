#ifndef SOCKET_UTIL
#define SOCKET_UTIL

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int createTCPIpv4Socket();

struct sockaddr_in* createIPv4Address(char* ip, int port);

#endif // SOCKET_UTIl
