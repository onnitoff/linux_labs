#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT_TCP 12346
#define BUFFER_SIZE 1024

int main() {
    int tcp_socket, new_socket, length;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    // Создание TCP сокета
    tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1) {
        perror("TCP socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Заполнение структуры адреса сервера
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_TCP);

    // Привязка сокета к адресу и порту
    if (bind(tcp_socket, (const struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("TCP socket bind failed");
        close(tcp_socket);
        exit(EXIT_FAILURE);
    }

    // Прослушивание сокета
    if (listen(tcp_socket, 5) == -1) {
        perror("TCP socket listen failed");
        close(tcp_socket);
        exit(EXIT_FAILURE);
    }

    printf("TCP Server listening on port %d...\n", PORT_TCP);
	while(1) {
    // Ожидание подключения клиента
    length = sizeof(client_addr);
    new_socket = accept(tcp_socket, (struct sockaddr*)&client_addr, (socklen_t*)&length);

    // Чтение данных от клиента
    memset(buffer, 0, BUFFER_SIZE);
    read(new_socket, buffer, BUFFER_SIZE);
    printf("TCP Client: %s\n", buffer);

    close(new_socket);
    }
    close(tcp_socket);

    return 0;
}

