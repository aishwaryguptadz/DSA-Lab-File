// Enqueue:
// Add the element to end of the heap.
// Restore the heap property by the comparing the added element with its parent. If it can violates the heap property, swap them.
// Continues this process up the heap until the correct position is found or root is reached.

// Dequeue:
// Replace the root of heap with the last element in the heap.
// Reduce the size of the heap by the one.
// Restore the heap property by the recursively comparing the new root with its children and swapping it 
// with the higher priority child in the max-heap or the lower priority child in the min heap.
// Continues this process down the heap until the correct position is found or the leaf is reached.

// Peek:
// Return the element at the root of the heap.

// Increase/Decrease key:
// Locate the element whose the priority needs to be updated.
// Update the priority of the element.
// If the priority is increased in the max-heap or decreased in the min-heap and it can restore the heap property by the heapifying up from the element.
// If the priority is decreased in the max-heap or increased in the min-heap and restore the heap property by the heapifying down from element.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int size;
} PriorityQueue;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->items[i]);
    }
    printf("\n");
}

void heapifyUp(PriorityQueue *pq, int index) {
    if (index && pq->items[(index - 1) / 2] > pq->items[index]) {
        swap(&pq->items[(index - 1) / 2], &pq->items[index]);
        heapifyUp(pq, (index - 1) / 2);
    }
}

void enqueue(PriorityQueue *pq, int value) {
    if (pq->size == MAX) {
        printf("Queue is full.\n");
        return;
    }
    pq->items[pq->size++] = value;
    heapifyUp(pq, pq->size - 1);
}

void heapifyDown(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < pq->size && pq->items[left] < pq->items[smallest]) smallest = left;
    if (right < pq->size && pq->items[right] < pq->items[smallest]) smallest = right;
    if (smallest != index) {
        swap(&pq->items[index], &pq->items[smallest]);
        heapifyDown(pq, smallest);
    }
}

int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = pq->items[0];
    pq->items[0] = pq->items[--pq->size];
    heapifyDown(pq, 0);
    return item;
}

int peek(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return pq->items[0];
}

int main() {
    PriorityQueue pq = {{0}, 0};
    int choice, value;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            enqueue(&pq, value);
            break;
        case 2:
            value = dequeue(&pq);
            if (value != -1) printf("Dequeued value: %d\n", value);
            break;
        case 3:
            value = peek(&pq);
            if (value != -1) printf("Top element is: %d\n", value);
            break;
        case 4:
            display(&pq);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}