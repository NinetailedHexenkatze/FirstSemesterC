#include <stdio.h>
#include "5th_Hotels.h"

int main(void) {
    Hotel hotels[] = {
        {"ОтельНомерОдин",      101, "люкс",     2, 8500.0},
        {"ОтельНомерОдинНоСДвумяБуквамиА",      205, "стандарт", 2, 3200.0},
        {"Балашиха",       310, "люкс",     3, 6000.0},
        {"ОтельНомерСНомером",     112, "полулюкс", 2, 4500.0},
        {"ОтельНомерСНомеромНоСДвумяБуквамиА",   401, "люкс",     4, 12000.0},
        {"Отель",    105, "эконом",   1, 2100.0}
    };

    int count = sizeof(hotels) / sizeof(hotels[0]);
    double max_luxury_price;

    printf("Исходный список номеров:\n");
    for (int i = 0; i < count; i++) {
        print_hotel(&hotels[i]);
    }

    find_two_a_hotels(hotels, count);
    printf("\nВведите максимальную стоимость для номера 'люкс': ");
    if (scanf("%lf", &max_luxury_price) == 1) {
        find_luxury_by_price(hotels, count, max_luxury_price);
    } else {
        printf("Ошибка ввода стоимости.\n");
    }

    return 0;
}