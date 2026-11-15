#include "5th_Hotels.h"
#include <stdio.h>
#include <string.h>


static int count_letter_a(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'A') {
            count++;
        }
        else if ((unsigned char)str[i] == 0xD0 &&
                ((unsigned char)str[i + 1] == 0xB0 || (unsigned char)str[i + 1] == 0x90)) {
            count++;
            i++;
                }
    }
    return count;
}

void print_hotel(const Hotel *h) {
    printf("Гостиница: %-15s | Номер: %-4d | Класс: %-10s | Мест: %d | Цена: %.2f\n",
           h->name, h->room_number, h->comfort, h->capacity, h->price);
}

void find_two_a_hotels(const Hotel *list, int count) {
    int found = 0;
    printf("\nНомера в гостиницах с двумя буквами 'а' в названии:\n");
    for (int i = 0; i < count; i++) {
        if (count_letter_a(list[i].name) == 2) {
            print_hotel(&list[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Подходящих номеров не найдено.\n");
    }
}

void find_luxury_by_price(const Hotel *list, int count, double max_price) {
    int found = 0;
    printf("\nНомера класса 'люкс' со стоимостью не более %.2f \n", max_price);
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].comfort, "люкс") == 0 && list[i].price <= max_price) {
            print_hotel(&list[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Подходящих номеров не найдено.\n");
    }
}