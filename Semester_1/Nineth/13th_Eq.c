#include "13th_Eq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_item(Oborudovanie **head, int inv_number, const char *name,
              const char *purchase_date, double price, const char *room) {
    Oborudovanie *new_node = (Oborudovanie *)malloc(sizeof(Oborudovanie));
    if (!new_node) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    new_node->inv_number = inv_number;
    strncpy(new_node->name, name, MAX_STR - 1);
    new_node->name[MAX_STR - 1] = '\0';

    strncpy(new_node->purchase_date, purchase_date, 19);
    new_node->purchase_date[19] = '\0';

    new_node->price = price;

    strncpy(new_node->room, room, 29);
    new_node->room[29] = '\0';

    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Oborudovanie *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_all(const Oborudovanie *head) {
    if (!head) {
        printf("Список пуст.\n");
        return;
    }
    printf("\nВесь список оборудования\n");
    while (head != NULL) {
        printf("Инв. №: %d | %s | Дата: %s | Цена: %.2f | Ауд.: %s\n",
               head->inv_number, head->name, head->purchase_date, head->price, head->room);
        head = head->next;
    }
}

void count_by_name(const Oborudovanie *head) {
    if (!head) {
        printf("Список пуст.\n");
        return;
    }

    printf("\nКоличество оборудования по наименованиям\n");
    const Oborudovanie *curr = head;

    while (curr != NULL) {
        int already_counted = 0;
        const Oborudovanie *prev = head;
        while (prev != curr) {
            if (strcmp(prev->name, curr->name) == 0) {
                already_counted = 1;
                break;
            }
            prev = prev->next;
        }
        if (!already_counted) {
            int count = 0;
            const Oborudovanie *temp = curr;
            while (temp != NULL) {
                if (strcmp(temp->name, curr->name) == 0) {
                    count++;
                }
                temp = temp->next;
            }
            printf("%s: %d шт.\n", curr->name, count);
        }

        curr = curr->next;
    }
}

void filter_by_price_and_room(const Oborudovanie *head, double max_price, const char *target_room) {
    printf("\nОборудование в ауд. '%s' стоимостью не выше %.2f \n", target_room, max_price);
    int found = 0;

    while (head != NULL) {
        if (strcmp(head->room, target_room) == 0 && head->price <= max_price) {
            printf("Инв. №: %d | %s | Дата: %s | Цена: %.2f\n",
                   head->inv_number, head->name, head->purchase_date, head->price);
            found = 1;
        }
        head = head->next;
    }

    if (!found) {
        printf("Подходящее оборудование не найдено.\n");
    }
}

void free_list(Oborudovanie **head) {
    Oborudovanie *curr = *head;
    while (curr != NULL) {
        Oborudovanie *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}
