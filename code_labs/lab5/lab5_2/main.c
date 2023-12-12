#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) { // проверяется, что программа была запущена с одним аргументом командной строки
        fprintf(stderr, "Использование: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char url[MAX_BUFFER_SIZE]; // url
    snprintf(url, MAX_BUFFER_SIZE, "%s", argv[1]); // url устанавливается из второгшо аргумента командной строки

    // Получаем информацию о хосте url
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(url, "http", &hints, &res);
    if (status != 0) {
        fprintf(stderr, "Ошибка getaddrinfo: %s\n", gai_strerror(status));
        return EXIT_FAILURE;
    }

    // Создаем сокет
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("Ошибка создания сокета");
        freeaddrinfo(res);
        return EXIT_FAILURE;
    }

    // Устанавливаем соединение
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("Ошибка соединения");
        close(sockfd);
        freeaddrinfo(res);
        return EXIT_FAILURE;
    }

    // Отправляем запрос на сервер
    char request[MAX_BUFFER_SIZE];
    snprintf(request, MAX_BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
    send(sockfd, request, strlen(request), 0);

    // Получаем и выводим ответ от сервера
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Освобождаем ресурсы
    close(sockfd);
    freeaddrinfo(res);

    return EXIT_SUCCESS;
}

