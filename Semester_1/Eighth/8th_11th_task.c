// #include <stdio.h>
// #include <string.h>
// #include "11th_Function.h"
//
// int main(void) {
//     char text[256];
//
//     printf("Введите строку: ");
//     if (fgets(text, sizeof(text), stdin) != NULL) {
//         //stdin безопасно считывает,
//         text[strcspn(text, "\n")] = '\0';
//     //strcspn безопасна удаляет перенос строки после ввода тексат
//         int result = count_digits(text);
//         printf("Количество цифр в строке: %d\n", result);
//     }
//
//     return 0;
// }