#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    
   // setlocale(LC_ALL, "Russian");

    // Вводим размер массива
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    // Проверка на корректность размера массива
    if (n <= 0) {
        cout << "Размер массива должен быть положительным числом." << endl;
        return 1;
    }

    // Создаем массив вещественных чисел
    double* arr = new double[n];

    // Вводим элементы массива
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    // Ищем первый положительный элемент
    int firstPositiveIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            firstPositiveIndex = i;
            break;
        }
    }

    // Если нет положительных элементов
    if (firstPositiveIndex == -1) {
        cout << "В массиве нет положительных элементов." << endl;
        delete[] arr;  // Освобождаем память
        return 0;
    }

    // Ищем последний положительный элемент
    int lastPositiveIndex = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            lastPositiveIndex = i;
            break;
        }
    }

    // Если первый положительный элемент идет после последнего
    if (firstPositiveIndex >= lastPositiveIndex) {
        cout << "В массиве нет положительных элементов, расположенных друг за другом." << endl;
        delete[] arr;  // Освобождаем память
        return 0;
    }

    // Находим минимальный элемент массива
    double minElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    // Вычисляем сумму элементов между первым и последним положительными элементами
    double sumBetweenPositives = 0;
    for (int i = firstPositiveIndex + 1; i < lastPositiveIndex; i++) {
        sumBetweenPositives += arr[i];
    }

    // Выводим результаты
    cout << "Минимальный элемент массива: " << minElement << endl;
    cout << "Сумма элементов между первым и последним положительными: " << sumBetweenPositives << endl;

    // Освобождаем память
    delete[] arr;

    return 0;
}

