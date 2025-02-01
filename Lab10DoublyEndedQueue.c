// Insert at front:
// First, check the position of the front in our array.
// If front < 1 , reinitialize front as the last index of the array i.e. front = N-1.
// Then, add new element to array[front].

// Insert at rear:
// First, check if the deque is full or not.
// If the deque is full , reinitialize rear with 0 (rear = 0) else increase rear by 1.
// Then, add the element to array[rear].

// Deletion at front:
// First, check if deque is empty or not.
// If the deque is empty (front == -1), then we cannot perform deletion operation. In this condition, we will simply print undeflow. 
// If deque contains only 1 element (front = rear) , then only one deletion operation can be performed. set front = -1 and rear = -1.
// Else if the front is at the last index ( front == n-1 ) , set front at starting index of deque (front = 0).
// If none of the above case exists, just increment front by 1 (front = front + 1). 

// Deletion at rear:
// First, check if the deque is empty or not.
// If the deque is empty (front = -1), then deletion operation cannot be performed and we will print underflow.
// If the deque has only 1 element( front==rear), we will set front = -1 and rear =-1.
// If the rear is at the starting index of deque (rear == 0) , then set rear to last index (rear = n-1).
// If none of the above case exists, just decrement rear by 1 (rear = rear-1).

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int key) {
    if (isFull()) return;
    if (front == -1) {
        front = 0;
        rear = 0;
    } 
    else if (front == 0) front = MAX - 1;
    else front = front - 1;
    deque[front] = key;
    printf("Inserted %d at the front.\n", key);
}

void insertRear(int key) {
    if (isFull()) return;
    if (rear == -1) {
        front = 0;
        rear = 0;
    } 
    else if (rear == MAX - 1) rear = 0;
    else rear = rear + 1;
    deque[rear] = key;
    printf("Inserted %d at the rear.\n", key);
}

void deleteFront() {
    if (isEmpty()) return;
    int removed = deque[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } 
    else if (front == MAX - 1) front = 0;
    else front = front + 1;
    printf("Deleted %d from the front.\n", removed);
}

void deleteRear() {
    if (isEmpty()) return;
    int removed = deque[rear];
    if (front == rear) {
        front = -1;
        rear = -1;
    } 
    else if (rear == 0) rear = MAX - 1;
    else rear = rear - 1;

    printf("Deleted %d from the rear.\n", removed);
}

void displayDeque() {
    if (isEmpty()) return;
    printf("Deque elements are: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, key;

    while (1) {
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display Deque\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Element to insert at front: ");
            scanf("%d", &key);
            insertFront(key);
            break;
        case 2:
            printf("Element to insert at rear: ");
            scanf("%d", &key);
            insertRear(key);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            displayDeque();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
