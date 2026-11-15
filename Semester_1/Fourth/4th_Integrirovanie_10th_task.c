// #include <stdio.h>
// #include <math.h>
// #include "integrirovanie_sin2x.h"
//
// int main()
// {
//     double a, b, eps;
//     printf("Эта программа вычисляет интеграл от sin2x\n");
//     printf("Введите начало интервала (a)\n");
//     scanf("%lf", &a);
//     printf("Введите конец интервала (b)\n");
//     scanf("%lf", &b);
//     printf("Введите желаемую точность eps\n");
//     scanf("%lf", &eps);
//     int iter_simp = 0;
//     int iter = 0;
//     printf("1. Аналитическое значение интеграла: %0.12f\n\n", fint(a, b));
//
//     trapetsiey(a, b, eps, &iter);
//     simpson(a, b, eps, &iter);
//
//     return 0;
// }