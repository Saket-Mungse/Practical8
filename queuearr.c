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
    if(R == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if(F == -1 && R == -1) {
        R = 0;
        F = 0;
    } else {
        R = R + 1;
    }
    MyQueue[R] = item;
    printf("Item inserted\n");
}

void dequeue() {
    int item;
    if(F == -1 || F > R) {
        printf("Underflow\n");
        return;
    } else {
        item = MyQueue[F];
        if(F == R) {
            F = -1;
            R = -1;
        } else {
            F = F + 1;
        }
        printf("Deleted item: %d\n", item);
    }
}

void display() {
    int i;
    if(R == -1) {
        printf("Empty\n");
    } else {
        printf("Queue contents: ");
        for(i = F; i <= R; i++) {
            printf("%d ", MyQueue[i]);
        }
        printf("\n");
    }
}

