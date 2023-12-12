#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT_UDP 12345
#define BUFFER_SIZE 1024

int main() {
    int udp_socket, length;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    // Создание UDP сокета
    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_socket == -1) {
        perror("UDP socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Заполнение структуры адреса сервера
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_UDP);

    // Привязка сокета к адресу и порту
    if (bind(udp_socket, (const struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("UDP socket bind failed");
        close(udp_socket);
        exit(EXIT_FAILURE);
    }

    printf("UDP Server listening on port %d...\n", PORT_UDP);

    while (1) {
        // Ожидание данных от клиента
        length = sizeof(client_addr);
        memset(buffer, 0, BUFFER_SIZE);
        recvfrom(udp_socket, (char*)buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &length);

        printf("UDP Client: %s\n", buffer);
    }

    close(udp_socket);

    return 0;
}

