/**
* @file lab5_3.cpp
* @author Пацалюк А.В., гр. 515-і2
* @date 26 травня 2024
* @brief Лабораторна робота № 5
*
* Застосування вказівників. Завдання 3
*/
#include <stdio.h>

// Функція для множення двох матриць
void mul_matrix(int* m1, int* m2, int* m3, int n, int m, int l) {
    // Ініціалізація матриці результату нулями
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            *(m3 + i * l + j) = 0;
        }
    }

    // Множення матриць
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            for (int k = 0; k < m; ++k) {
                *(m3 + i * l + j) += *(m1 + i * m + k) * *(m2 + k * l + j);
            }
        }
    }
}

int main() {
    // Розміри матриць
    int n = 2, m = 3, l = 2;

    // Матриця m1 розміру nxm
    int m1[] = {
        1, 2, 3,
        4, 5, 6
    };

    // Матриця m2 розміру mxl
    int m2[] = {
        7, 8,
        9, 10,
        11, 12
    };

    // Матриця результату m3 розміру nxl
    int m3[4] = { 0 };

    // Виклик функції множення матриць
    mul_matrix(m1, m2, m3, n, m, l);

    // Виведення результатів
    printf("Result matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            printf("%d ", *(m3 + i * l + j));
        }
        printf("\n");
    }

    return 0;
}
