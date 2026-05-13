#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(void) {
    
    int sockD = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_port = htons(9001);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int connectStatus = connect(sockD, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    if (connectStatus == -1) {
        printf("Error \n");
    } else {
        char strData[255];

        recv(sockD, strData, sizeof(strData), 0);
        printf("Message %s", strData);
    }
    return 0;
}

