// #include <stdio.h>
// #include <stdlib.h>
// #include "4th_pairs.h"
//
// int main()
// {
//     size_t n = 5;
//     printf("Размер массива - 5, из двух одинаковых пар ключей останется та, у которой значение больше\n");
//     printf("Сначала вводите ключ а уже потом значение!\n");
//     int *keys = (int *) malloc(n * sizeof(int));
//     int *values = (int *) malloc(n * sizeof(int));
//
//     printf("Введите 2 значения: keys[0] и values[0]\n");
//     scanf("%d", &keys[0]);
//     scanf("%d", &values[0]);
//     printf("Введите 2 значения: keys[1] и values[1]\n");
//     scanf("%d", &keys[1]);
//     scanf("%d", &values[1]);
//     printf("Введите 2 значения: keys[2] и values[2]\n");
//     scanf("%d", &keys[2]);
//     scanf("%d", &values[2]);
//     printf("Введите 2 значения: keys[3] и values[3]\n");
//     scanf("%d", &keys[3]);
//     scanf("%d", &values[3]);
//     printf("Введите 2 значения: keys[4] и values[4]\n");
//     scanf("%d", &keys[4]);
//     scanf("%d", &values[4]);
//
//     KeyValuePairPtr *pairs = (KeyValuePairPtr *) malloc(n * sizeof(KeyValuePairPtr));
//     for (size_t i = 0; i < n; i++)
//     {
//         pairs[i].key_ptr = &keys[i];
//         pairs[i].val_ptr = &values[i];
//     }
//
//     printf("Исходные пары: ");
//     for (size_t i = 0; i < n; i++)
//     {
//         printf("Ключ: %d, Значение %d\n", *(pairs[i].key_ptr), *(pairs[i].val_ptr));
//     }
//
//     remove_duplicate_pairs(&pairs, &n);
//
//     printf("После удаления дубликатов:\n");
//     for (size_t i = 0; i < n; i++)
//     {
//         printf("Ключ: %d, Значение %d\n", *(pairs[i].key_ptr), *(pairs[i].val_ptr));
//     }
//
//     free(keys);
//     free(values);
//     free(pairs);
//
//     return 0;
// }