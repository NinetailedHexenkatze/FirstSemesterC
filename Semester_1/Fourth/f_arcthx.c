#include "f_arctgx.h"
#include <math.h>
#include <stdlib.h>

double f1(double x, double eps)
{
    int i = 0;
    double a = 0.0;
    while (pow(a - atan(x), 2) > pow(eps, 2))
    {
        a += (pow(-1*1.0, i)*pow(x, 2*i + 1)) / (2*i + 1);
        i++;

    }

    return a;

}
