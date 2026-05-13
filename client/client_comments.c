#include <netinet/in.h> // provide structures and constants for internet addresses (sockaddr_in, INADDR_ANY, htons(), etc)
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> // provide the sockets functions (recv(), connect(), send(), socket(), etc)
#include <sys/types.h> // define data types like socklen_t, etc 

int main(void) {
    // create a socket, the function socket() will return a file descriptor
    // file descriptor: eh um identificador de um arquivo/recurso aberto dentro de um processo
    // AF_INET: familia de enderecos: IPv4 (protocolo para identificar dispositivos em uma rede)
    // SOCK_STREAM: tipo de socket (fluxo de bytes confiavel e orientado a conexao, bem usado quando falamos de TCP)
    // 0: numero do protocolo, faz o sistema escolher o protocolo patrao para SOCK_STREAM
    int sockD = socket(AF_INET, SOCK_STREAM, 0);

    if (sockD == -1) {
        printf("Error to create a socket \n");
    } 

    // this is a struct designed to hold an IPv4 addres and port number
    struct sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET; // se refere a familia de protolocos
    serverAddr.sin_port = htons(9001); // numero da porta do servidor, Host TO Network Short converte a porta do formato do seu computador, isso garante que a porta seja interpretada de forma correta em qualquer pc 
    serverAddr.sin_addr.s_addr = INADDR_ANY; // endereco IPv4 do servidor, INADDR_ANY significa "qualquer endereco local" (se for em outra maquina coloque o IP real do servidor)

    // criar uma conexao com o servidor
    // 1 -> descritor do socket do cliente
    // 2 -> ponteiro para struct sockaddr (genérico) por isso o cast 
    // 3-> tamanho da estrutura
    int connectStatus = connect(sockD, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    if (connectStatus == -1) {
        printf("Error \n");
    } else {
        // se receber valores ele vai imprimir
        
        // tamanho em bytes para ser o limite da mensagem
        char strData[255];

        // 0 significa comportamento padrão (sem dados fora‑de‑banda, sem espiar)
        // retorna o tamanho da mensagem se for um sucesso
        size_t sizeMSG = recv(sockD, strData, sizeof(strData), 0);
        printf("Size of Message: %zu, Message %s", sizeMSG, strData);
    }
    return 0;
}

