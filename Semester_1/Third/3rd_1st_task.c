// #include <stdio.h>
//
// #define N 5
//
// int main(void)
// {
//     float x[N];
//     float y[N];
//
//     printf("\nПриближение линейной функции методом наименьших квадратов");
//     printf("\nВнимание! Размер массива равен пяти, если вам не хватает - обратитесь куда-нибудь");
//
//     float sum_x = 0;
//     float sum_y = 0;
//     float sum_xy = 0;
//     float sum_x2 = 0;
//     float a;
//     float b;
//
//     printf("\nВведите %d точек (координаты x и y через пробел):\n", N);
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%f %f", &x[i], &y[i]);
//
//         sum_x += x[i];
//         sum_y += y[i];
//         sum_x2 += x[i]*x[i];
//         sum_xy += x[i]*y[i];
//     }
//
//     float den = N * sum_x2 - sum_x * sum_x;
//     if (den == 0)
//     {
//         printf("Извините, координаты одинаковы, ни с чем помочь не сможем");
//         return 1;
//     }
//
//     a = (N * sum_xy - sum_x * sum_y) / den;
//     b = (sum_y - a * sum_x) / N;
//
//     printf("\nВычисления проведены успешно! Ответ:");
//     printf("\ny = ax + b, где:");
//     printf("a = %.4f\n", a);
//     printf("b = %.4f\n", b);
//     printf("Уравнение наилучшего приближения: y = %.4f * x + (%.4f)\n", a, b);
//
//     return 0;
// }