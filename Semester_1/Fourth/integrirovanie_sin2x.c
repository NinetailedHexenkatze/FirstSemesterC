#include "integrirovanie_sin2x.h"
#include <stdio.h>
#include <math.h>

double fint(double a, double b)
{
    double sin_b = sin(b);
    double sin_a = sin(a);
    return (sin_b*sin_b) - (sin_a*sin_a);
}

void trapetsiey(double a, double b, double eps, int *iter)
{
    int n = 2;
    double h = (b - a) / n;
    double sum = 0.5*(sin(a * 2.0) + sin(b * 2.0)) + sin((a + h) * 2.0);
    double iold = sum * h;
    double inew = 0;

    *iter = 0;

    while (1)
    {
        (*iter)++;
        n *= 2;
        h = (b - a) / n;

        double current_sum = 0;
        for (int i = 1; i < n; i+= 2)
        {
            current_sum += sin((a + i*h)*2.0);
        }
        inew = 0.5*iold + current_sum*h;

        if (fabs(inew - iold)/3.0 < eps)
        {
            break;
        }
        iold = inew;
    }
    printf("2. Метод трапеций\n");
    printf("Численное значение: %0.12f\n", inew);
    printf("Количество итераций: %d\n", *iter);
}

void simpson(double a, double b, double eps, int *iter)
{
    int n = 2;
    double h = (b - a) / n;
    double iold = (h/3.0) * (sin(a * 2.0) + 4.0 * sin(2.0*(a + h)) + sin(2.0 * b));
    double inew = 0;

    *iter = 0;
    while (1) {
        (*iter)++;
        n *= 2;
        h = (b - a) / n;

        double sum_k4 = 0;
        double sum_k2 = 0;

        for (int i = 1; i < n; i++)
        {
            if (i % 2 != 0)
            {
                sum_k4 += sin((a + i * h)*2.0);
            }
            else
            {
                sum_k2 += sin((a + i * h)*2.0);
            }
        }

    inew = (h / 3.0) * (sin(2.0 * a) + sin(2.0 * b) + 4.0 * sum_k4 + 2.0 * sum_k2);
    if (fabs(inew - iold)/15.0 < eps) {
        break;
    }
    }
    printf("3. Метод Симпсона\n");
    printf("Численное значение: %0.12f\n", inew);
    printf("Количество итераций: %d\n", *iter);
}