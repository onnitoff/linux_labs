#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT_UDP 12345
#define BUFFER_SIZE 1024

int main() {
    int udp_socket;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // Создание UDP сокета
    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_socket == -1) {
        perror("UDP socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Заполнение структуры адреса сервера
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_UDP);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Отправка данных серверу
    printf("Enter message for UDP Server: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    sendto(udp_socket, (const char*)buffer, strlen(buffer), 0, (const struct sockaddr*)&server_addr, sizeof(server_addr));

    close(udp_socket);

    return 0;
}

