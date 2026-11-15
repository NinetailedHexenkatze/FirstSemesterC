// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include "sortirovka.h"
//
// #define size 10
//
// int main(void)
// {
//     printf("\nСортировка массива действительных чисел");
//     printf("\nВнимание! Массив состоит только из 10 элементов");
//
//     double arr[size];
//
//     srand(time(NULL));
//
//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = ((double)rand() / RAND_MAX)* 100.0;
//     }
//
//     printf("\nСгенерированный массив:\n");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%lf\n", arr[i]);
//     }
//
//     printf("\n Сортировка началась, пожалуйста, подождите\n");
//
//     sortirovka(arr, size);
//
//
//     return 0;
// }