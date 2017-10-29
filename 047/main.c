#include <stdio.h>

/* Умножение матриц */
int main(void)
{
    int a[10][10], b[10][10], result[10][10], r1, c1, r2, c2, i, j, k;

    printf("Введите количество строк и колонок первой матрицы: ");
    scanf("%d %d", &r1, &c1);

    printf("Введите количество строк и колонок второй матрицы: ");
    scanf("%d %d", &r2, &c2);

    // Проверяем можем ли мы умножить две матрицы
    while (c1 != r2) {
        printf("Ошибка! Количество колонок первой матрицы не равно количеству строк второй\n\n");
        printf("Введите количество строк и колонок первой матрицы: ");
        scanf("%d %d", &r1, &c1);
        printf("Введите количество строк и колонок второй матрицы: ");
        scanf("%d %d", &r2, &c2);
    }

    /* Считываем элементы 1 матрицы */
    printf("\nВведите элементы 1 матрицы:\n");

    for (i = 0; i < r1; ++i) {
        for (j=0;j<c1;++j) {
            printf("Введите элемент a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    /* Считываем элементы 2 матрицы */
    printf("\nВведите элементы 2 матрицы:\n");

    for (i = 0; i < r2; ++i) {
        for (j = 0; j < c2; ++j) {
            printf("Введите элемент a%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    /* Заполняем все элементы результирующей матрицы нулями */
    for (i = 0; i < r2; ++i) {
        for (j = 0; j < c2; ++j)
            result[i][j]=0;
    }

    /*
     * Умножаем матрицы a и b
     * Результат сохраняем в матрице result
     */
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            for (k = 0; k < c1; ++k)
                result[i][j] += a[i][k] * b[k][j];
        }
    }

    /* Отображаем результат */
    printf("\nРезультат умножения матриц:\n");

    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            printf("%d   ", result[i][j]);

            if (j == c2 - 1)
                printf("\n\n");
        }
    }

    return 0;
}