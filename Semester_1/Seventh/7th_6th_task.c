// #include <stdio.h>
// #include "6th_Functions.h"
//
// int main() {
//     char buffer[512];
//     int N, M;
//     double x0, xk;
//
//     printf("Введите количество строк N: ");
//     if (scanf("%d", &N) != 1 || N <= 0) {
//         printf("Ошибка ввода N\n");
//         return 1;
//     }
//
//     printf("Введите количество колонок M: ");
//     if (scanf("%d", &M) != 1 || M <= 0) {
//         printf("Ошибка ввода M\n");
//         return 1;
//     }
//
//     printf("Введите начальное x0: ");
//     if (scanf("%lf", &x0) != 1) {
//         printf("Ошибка ввода x0\n");
//         return 1;
//     }
//
//     printf("Введите конечное xH: ");
//     if (scanf("%lf", &xk) != 1) {
//         printf("Ошибка ввода xk\n");
//         return 1;
//     }
//
//     const char *file1_path = "file1.txt";
//     const char *file2_path = "file2.txt";
//
//     // Шаг 1: Запись исходной таблицы
//     if (!write_initial_table(file1_path, N, M, x0, xk)) {
//         printf("Не удалось создать файл %s\n", file1_path);
//         return 1;
//     }
//     printf("\nИсходная таблица сохранена в %s\n", file1_path);
//
//     FILE *f1 = fopen(file1_path, "r");
//     if (f1) {
//         printf("Содержимое первого файла\n");
//         while (fgets(buffer, sizeof(buffer), f1) != NULL) {
//             printf("%s", buffer);
//         }
//         fclose(f1);
//     }
//
//     if (!filter_table(file1_path, file2_path, N, M)) {
//         printf("Ошибка при обработке данных во второй файл\n");
//         return 1;
//     }
//     printf("\nОтфильтрованная таблица сохранена в %s\n", file2_path);
//     FILE *f2 = fopen(file2_path, "r");
//     if (f2) {
//         printf("Содержимое файла 2 где числа больше среднего\n");
//         while (fgets(buffer, sizeof(buffer), f2) != NULL) {
//             printf("%s", buffer);
//         }
//         fclose(f2);
//     }
//
//     return 0;
// }
