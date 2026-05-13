#include <netinet/in.h> // estrutura para armazenar informações de endereço
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> // APIs de socket
#include <sys/types.h>

int main(int argc, char const* argv[])
{
    // cria o socket do servidor (igual ao cliente)
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);

    // string com a mensagem a ser enviada ao cliente
    char serMsg[255] = "Message from the server to the "
                       "client \'Hello Client\' ";

    // define o endereço do servidor
    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // associa o socket ao IP e porta especificados
    bind(servSockD, (struct sockaddr*)&servAddr,
         sizeof(servAddr));

    // coloca o socket em modo de escuta (listen)
    listen(servSockD, 1);

    // variável que guardará o socket do cliente aceito
    int clientSocket = accept(servSockD, NULL, NULL);

    // envia a mensagem para o socket do cliente
    send(clientSocket, serMsg, sizeof(serMsg), 0);

    return 0;
}
