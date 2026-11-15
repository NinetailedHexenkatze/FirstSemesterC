// #include <stdio.h>
// #include "8th_Queue.h"
//
// int main() {
//     Queue q;
//     queue_init(&q);
//
//     int m = 0;
//
//     printf("Заполнение начальной емкости %d\n", CHUNK_SIZE);
//     printf("Введите начальные значаения (Столько же шт сколько и емкость), для примера очередь будет заполняться до 12 значений\n");
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     queue_print(&q);
//
//     printf("Добавление элементов сверх емкости\n");
//     printf("Введите 4 значения значаения сверх начальной емкости\n");
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     queue_print(&q);
//
//     printf("Введите еще 4 значения\n");
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     scanf("%d", &m);
//     queue_enqueue(&q, m);
//     queue_print(&q);
//
//     printf("\nПервый элемент в очереди: %d\n", queue_peek(&q));
//
//     queue_free(&q);
//     return 0;
// }