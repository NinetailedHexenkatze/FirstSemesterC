#ifndef UNTITLED_8TH_QUEUE_H
#define UNTITLED_8TH_QUEUE_H

#define CHUNK_SIZE 4

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;

void queue_init(Queue *q);
int queue_is_empty(const Queue *q);
void queue_enqueue(Queue *q, int value);
int queue_dequeue(Queue *q);
int queue_peek(const Queue *q);
void queue_print(const Queue *q);
void queue_free(Queue *q);


#endif //UNTITLED_8TH_QUEUE_H
