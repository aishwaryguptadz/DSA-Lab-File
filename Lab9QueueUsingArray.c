#include <stdio.h>
#define MAX_SIZE 100

struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

int isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = data;
    printf("Enqueued %d\n", data);
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    int data = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    printf("Deleted element: %d\n", data);
    return data;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    int choice, value;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printf("Elements: ");
                display(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}