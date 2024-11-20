#include <stdio.h>
#define MAX 5

int R = -1;
int F = -1;
int MyQueue[MAX];

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    do {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);
    return 0;
}

void enqueue() {
    int item;
    printf("Enter item: ");
    scanf("%d", &item);

    if ((F == 0 && R == MAX - 1)) {
        printf("Overflow\n");
        return;
    }

    if (F == -1) { // Insert first element
        F = R = 0;
    } else if (R == MAX - 1) { // Wrap around
        R = 0;
    } else {
        R++;
    }
    MyQueue[R] = item;
    printf("Item inserted\n");
}

void dequeue() {
    if (F == -1) {
        printf("Underflow\n");
        return;
    }

    int item = MyQueue[F];
    printf("Deleted item: %d\n", item);

    if (F == R) { // Queue is now empty
        F = R = -1;
    } else if (F == MAX - 1) { // Wrap around
        F = 0;
    } else {
        F++;
    }
}

void display() {
    if (F == -1) {
        printf("Empty\n");
        return;
    }

    printf("Queue contents: ");
    if (R >= F) {
        for (int i = F; i <= R; i++) {
            printf("%d ", MyQueue[i]);
        }
    } else {
        for (int i = F; i < MAX; i++) {
            printf("%d ", MyQueue[i]);
        }
        for (int i = 0; i <= R; i++) {
            printf("%d ", MyQueue[i]);
        }
    }
    printf("\n");
}