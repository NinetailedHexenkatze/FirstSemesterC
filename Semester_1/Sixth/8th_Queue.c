#include <stdio.h>
#include <stdlib.h>
#include "8th_Queue.h"

void queue_init(Queue *q) {
    q->data = (int *)malloc(CHUNK_SIZE * sizeof(int));
    if (q->data == NULL) {
        perror("Ошибка выделения памяти при инициализации");
        exit(EXIT_FAILURE);
    }
    q->capacity = CHUNK_SIZE;
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}

int queue_is_empty(const Queue *q) {
    return q->size == 0;
}

void queue_enqueue(Queue *q, int value) {
    if (q->size == q->capacity) {
        int old_capacity = q->capacity;
        q->capacity += CHUNK_SIZE;

        int *new_data = (int *)malloc(q->capacity * sizeof(int));
        if (new_data == NULL) {
            perror("Ошибка выделения памяти при расширении очереди");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < q->size; i++) {
            new_data[i] = q->data[(q->front + i) % old_capacity];
        }

        free(q->data);
        q->data = new_data;
        q->front = 0;
        q->rear = q->size - 1;
        printf("\nПамять переполнена! Емкость увеличена на %d (Новая емкость: %d)\n\n", CHUNK_SIZE, q->capacity);
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
}

int queue_peek(const Queue *q) {
    if (queue_is_empty(q)) {
        fprintf(stderr, "Ошибка: Очередь пуста!\n");
        exit(EXIT_FAILURE);
    }
    return q->data[q->front];
}

void queue_print(const Queue *q) {
    if (queue_is_empty(q)) {
        printf("Очередь пуста.\n");
        return;
    }
    printf("Элементы очереди: ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->data[(q->front + i) % q->capacity]);
    }
    printf("[Размер: %d, Емкость: %d, Начало(index): %d, Конец(index): %d]\n",
            q->size, q->capacity, q->front, q->rear);
}

void queue_free(Queue *q) {
    free(q->data);
    q->data = NULL;
    q->capacity = 0;
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}