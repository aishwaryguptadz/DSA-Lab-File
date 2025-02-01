#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

typedef struct Queue {
    node* front;
    node* rear;
} queue;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

queue* createQueue()
{
    queue* newQueue = (queue*)malloc(sizeof(queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

int isEmpty(queue* q)
{
    return q->front == NULL;
}

void enqueue(queue* q, int data)
{
    node* newNode = createNode(data);
    if (!newNode) return;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(queue* q)
{
    if (isEmpty(q)) return -1;
    node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    int data = temp->data;
    free(temp);
    return data;
}

int peek(queue* q)
{
    if (isEmpty(q)) return -1;
    return q->front->data;
}

void printQueue(queue* q)
{
    node* temp = q->front;
    if (temp == NULL) return;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    queue* q = createQueue();
    int choice, data;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Print Queue\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            data = dequeue(q);
            if (data != -1) printf("Dequeued: %d\n", data);
            break;
        case 3:
            data = peek(q);
            if (data == -1) printf("Queue is empty.\n");
            else printf("Front element: %d\n", data);
            break;
        case 4:
            printf("Elements: ");
            printQueue(q);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}