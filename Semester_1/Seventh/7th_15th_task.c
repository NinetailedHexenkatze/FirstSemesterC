#include "15th_functions.h"

int main() {
    char buffer[256];
    int N, M;
    double x0, x_N;
    double max_fractional;

    const char *file1_path = "file1.txt";
    const char *file2_path = "file2.txt";

    printf("Введите целые числа N (строк) и M (колонок): ");
    if (scanf("%d %d", &N, &M) != 2 || N <= 0 || M <= 0) {
        printf("Ошибка ввода N или M.\n");
        return 1;
    }

    printf("Введите вещественные числа x0 и x_N: ");
    if (scanf("%lf %lf", &x0, &x_N) != 2) {
        printf("Ошибка ввода x0 или x_N.\n");
        return 1;
    }

    const char *file1 = "table1.txt";
    if (!write_table_to_file(file1, N, M, x0, x_N)) {
        printf("Не удалось создать первый файл.\n");
        return 1;
    }
    printf("Таблица успешно записана в файл '%s'.\n", file1);

    FILE *f1 = fopen(file1_path, "r");
    if (f1) {
        printf("Содержимое первого файла\n");
        while (fgets(buffer, sizeof(buffer), f1) != NULL) {
            printf("%s", buffer);
        }
        fclose(f1);
    }

    printf("\nВведите максимальное значение дробной части (например, 0.5): ");
    if (scanf("%lf", &max_fractional) != 1 || max_fractional < 0) {
        printf("Ошибка ввода граничного значения.\n");
        return 1;
    }

    const char *file2 = "table2.txt";
    if (!process_and_copy_file(file1, file2, N, M, max_fractional)) {
        printf("Ошибка при обработке и записи во второй файл.\n");
        return 1;
    }

    printf("Отфильтрованные данные успешно записаны в файл '%s'.\n", file2);
    FILE *f2 = fopen(file2_path, "r");
    if (f1) {
        printf("Содержимое первого файла\n");
        while (fgets(buffer, sizeof(buffer), f2) != NULL) {
            printf("%s", buffer);
        }
        fclose(f2);
    }
    return 0;
}