#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void enqueue();
void dequeue();
void printQueue();
void exitProgram();

struct Node* front = NULL; // Pointer to the front of the queue
struct Node* rear = NULL;  // Pointer to the rear of the queue
// Function to add an element to the queue
void enqueue() {
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

// Function to print the elements of the queue
void printQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to exit the program
void exitProgram() {
    printf("Exiting...\n");
    // Free memory before exiting
    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }
    exit(0);
}
int main() {
    int choice;
    do {
        printf("1. Add (Enqueue)\n2. Delete (Dequeue)\n3. Print\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
            case 4:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);
    return 0;
}
