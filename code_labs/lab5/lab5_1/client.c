#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 12345

void client(int number) {
    int client_socket;
    struct sockaddr_in server_addr;

    // Создание сокета
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Настройка адреса сервера
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Подключение к серверу
    connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Отправка данных серверу
    char buffer[1024];
    sprintf(buffer, "%d", number);
    send(client_socket, buffer, strlen(buffer), 0);

    // Получение результата от сервера
    recv(client_socket, buffer, sizeof(buffer), 0);

    printf("Результат для числа %d: %s\n", number, buffer);

    // Закрытие сокета
    close(client_socket);
}

int main() {
    client(160);
    return 0;
}

