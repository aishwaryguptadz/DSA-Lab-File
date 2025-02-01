// IsFull Implementation:
// Check if the front index is equal to the rear index.
// If true, the queue is empty; return true.
// Otherwise, return false.

// IsEmpty Implementation:
// Check if the (rear + 1) % MAX_SIZE is equal to the front index.
// If true, the queue is full; return true.
// Otherwise, return false.

// Enqueue Implementation:
// Check if the queue is full using the isFull function.
// If the queue is full, print "Queue Overflow" and return.
// Otherwise, increment the rear index using (rear + 1) % MAX_SIZE.
// Insert the new element at the rear index.

// Dequeue Implementation:
// Check if the queue is empty using the isEmpty function.
// If the queue is empty, print "Queue Underflow" and return.
// Otherwise, increment the front index using (front + 1) % MAX_SIZE.

// Peek Implementation:
// Check if the queue is empty using the isEmpty function.
// If the queue is empty, print "Queue is Empty" and return -1.
// Otherwise, return the element at (front + 1) % MAX_SIZE.

#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

int isEmpty()
{
    return front == -1;
}

void enqueue(int data)
{
    if (isFull()) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("%d inserted\n", data);
}

int dequeue()
{
    if (isEmpty()) return -1;
    int data = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX_SIZE;
    return data;
}

void display()
{
    if (isEmpty()) return;
    printf("Queue elements: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            data = dequeue();
            if (data != -1) printf("Dequeued element: %d\n", data);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
