// #include <stdio.h>
// #include <math.h>
//
// double f(double x)
// {
//     return log(x) - 1.0/x;
// }
//
// int main(void)
// {
//     // printf("%f\n", f(2.0));
//     double a = 1;
//     double b = 3;
//     double c = 0;
//     double pogreshnost = 0.1 * 0.1 * 0.1 * 0.1 * 0.1*0.1;
//     // это 10^(-6)
//     printf("В первую очередь выполняем цикл, который выполняется пока b - a больше погрешности");
//     printf(". Введите a и b - начало и конец отрезка");
//     scanf("%lf", &a);
//     scanf("%lf", &b);
//
//     while ((b - a)/2.0 > pogreshnost)
//     {
//         c = (b + a)/2.0;
//
//         if (f(c) == 0.0) {
//             printf("Корень успешно найден!");
//             break;
//         }
//         if (f(a)*f(c)< 0)
//         {
//             b = c;
//         }
//         else
//         {
//             a = c;
//         }
//     }
//     double answer = (a+b)/ 2.0;
//     printf("Ответ:");
//     printf("%f", answer);
//
//     return 0;
// }