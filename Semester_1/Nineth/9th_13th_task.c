#include <stdio.h>
#include "13th_Eq.h"

int main(void) {
    Oborudovanie *list = NULL;

    // Заполнение списка тестовыми данными
    add_item(&list, 10001, "Компьютер", "19.05.2029", 45000.0, "101");
    add_item(&list, 10002, "Проектор", "15.09.2022", 32000.0, "101");
    add_item(&list, 10003, "Компьютер", "20.09.2094", 55000.0, "102");
    add_item(&list, 10004, "Принтер", "03.10.9021", 18500.0, "101");
    add_item(&list, 10005, "Компьютер", "12.05.2023", 45000.0, "101");
    add_item(&list, 10006, "Проектор", "10.02.2022", 29000.0, "102");
    print_all(list);
    count_by_name(list);

    char target_room[30];
    double max_price;

    printf("\nВведите номер аудитории для поиска: ");
    scanf("%29s", target_room);

    printf("Введите максимальную стоимость: ");
    scanf("%lf", &max_price);

    filter_by_price_and_room(list, max_price, target_room);
    free_list(&list);

    return 0;
}