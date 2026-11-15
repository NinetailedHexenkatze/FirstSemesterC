#include <ctype.h>
#include "11th_Function.h"

int count_digits(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit((unsigned char)str[i])) {
            count++;
        }
    }
    return count;
}