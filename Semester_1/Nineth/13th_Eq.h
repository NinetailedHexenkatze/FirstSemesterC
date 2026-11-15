#ifndef FIRSTSEMESTERC_13TH_EQ_H
#define FIRSTSEMESTERC_13TH_EQ_H

#define MAX_STR 100

typedef struct Oborudovanie {
    int inv_number;
    char name[MAX_STR];
    char purchase_date[20];
    double price;
    char room[30];
    struct Oborudovanie *next;
} Oborudovanie;
void add_item(Oborudovanie **head, int inv_number, const char *name,
              const char *purchase_date, double price, const char *room);
void print_all(const Oborudovanie *head);
void count_by_name(const Oborudovanie *head);
void filter_by_price_and_room(const Oborudovanie *head, double max_price, const char *target_room);
void free_list(Oborudovanie **head);

#endif //FIRSTSEMESTERC_13TH_EQ_H
