#ifndef FIRSTSEMESTERC_5TH_HOTELS_H
#define FIRSTSEMESTERC_5TH_HOTELS_H

#define MAX_STR 100

typedef struct {
    char name[MAX_STR];
    int room_number;
    char comfort[MAX_STR];
    int capacity;
    double price;
} Hotel;

void print_hotel(const Hotel *h);
void find_two_a_hotels(const Hotel *list, int count);
void find_luxury_by_price(const Hotel *list, int count, double max_price);

#endif //FIRSTSEMESTERC_5TH_HOTELS_H
