#include <iostream>
using namespace std;


const int MAX_ROWS = 4;
const int MAX_COLS = 4;

int findMaxRepeatedNumber(int matrix[MAX_ROWS][MAX_COLS]) {
    const int maxNumber = 1000;  // Предполагаем максимальное значение числа в матрице

    // Используем массивы для подсчета встреч каждого числа в матрице
    int countMap[maxNumber + 1] = { 0 };

    // Подсчитываем количество встреч каждого числа в матрице
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            countMap[matrix[i][j]]++;
        }
    }

    int maxRepeatedNumber = -1;
    int maxCount = 1;

    // Находим максимальное число, встречающееся более одного раза
    for (int i = 0; i <= maxNumber; ++i) {
        if (countMap[i] > 1 && countMap[i] > maxCount) {
            maxCount = countMap[i];
            maxRepeatedNumber = i;
        }
    }

    return maxRepeatedNumber;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Пример матрицы
    int matrix[MAX_ROWS][MAX_COLS] = {
        {4, 4, 3, 4},
        {5, 6, 3, 1},
        {6, 7, 6, 9},
        {1, 2, 3, 6}
    };

    int maxRepeatedNumber = findMaxRepeatedNumber(matrix);

    if (maxRepeatedNumber != -1) {
        cout << "Максимальное число, встречающееся более одного раза: " << maxRepeatedNumber << endl;
    }
    else {
        cout << "В матрице нет чисел, встречающихся более одного раза." << endl;
    }

    return 0;
}

