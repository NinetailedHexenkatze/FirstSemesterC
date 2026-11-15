#include "f_19_arccosx.h"
#include <math.h>
#include <stdlib.h>

double f19thTask(double x, double eps)
{
    int i = 0;
    double a = 0.0;
    double nech = 1.0;
    double ch = 1.0;
    double sum = 0.0;

    while (pow(a - acos(x), 2) > pow(eps, 2))
    {
        for (int num = 1; num <= (i * 2 + 1); num++)
        {
            if (num % 2 == 0)
            {
                ch *= num;
            }
            else
            {
                nech *= num;
            }
        }
        sum = (nech * (pow(x, 2*i +1)))/(ch * (2*i + 1));
        a = (M_PI / 2) - x - sum;
        i++;
    }
    return a;

}