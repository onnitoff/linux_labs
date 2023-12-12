#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT_TCP 12346
#define BUFFER_SIZE 1024

int main() {
    int tcp_socket;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // Создание TCP сокета
    tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1) {
        perror("TCP socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Заполнение структуры адреса сервера
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_TCP);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Подключение к серверу
    if (connect(tcp_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("TCP socket connect failed");
        close(tcp_socket);
        exit(EXIT_FAILURE);
    }

    // Отправка данных серверу
    printf("Enter message for TCP Server: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    write(tcp_socket, buffer, strlen(buffer));

    close(tcp_socket);

    return 0;
}

