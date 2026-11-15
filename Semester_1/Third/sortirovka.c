#include "sortirovka.h"

#include <stdio.h>

void sortirovka(double arr[], int size)
{
    int comparations = 0;
    int permutations = 0;

    for (int i = 1; i < size; i++) {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparations++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                permutations++;
                j--;
            }
            else
            {
                break;
            }
        }
        arr[j+1] = key;
    }
    printf("\nСортировка завершена! Получившийся массив:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%lf\n", arr[i]);
    }
    printf("\nКоличество сравнений: %d\n", comparations);
    printf("\nКоличество перестановок: %d\n", permutations);

}
