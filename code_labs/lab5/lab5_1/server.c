#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 12345

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Создание сокета
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Настройка адреса сервера
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Привязка сокета к адресу
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Ожидание подключения клиента
    listen(server_socket, 5);
    printf("Сервер запущен. Ожидание подключения клиента...\n");

   

    while (1) {
     // Принятие подключения
    	client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
  	printf("Подключен клиент\n");
  	
        char buffer[2048];
        int num, result;

        // Получение данных от клиента
        recv(client_socket, buffer, sizeof(buffer), 0);

        // Преобразование строки в число
        num = atoi(buffer);

        // Вычисление квадрата числа
        result = num*num;

        // Отправка результата клиенту
        sprintf(buffer, "%d", result);
        send(client_socket, buffer, strlen(buffer), 0);
        close(client_socket);
    }

    // Закрытие сокетов

    close(server_socket);

    return 0;
}

