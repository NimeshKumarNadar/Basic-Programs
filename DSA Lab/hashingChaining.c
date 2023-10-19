#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* table[TABLE_SIZE];

// Initialize the hash table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

// Hash function to determine the index in the table
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a value into the hash table
void insert(int key) {
    int index = hashFunction(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = table[index];

    table[index] = newNode;
}

// Search for a value in the hash table
int search(int key) {
    int index = hashFunction(key);

    struct Node* current = table[index];
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Found
        }
        current = current->next;
    }

    return 0; // Not found
}

// Delete a value from the hash table
void delete(int key) {
    int index = hashFunction(key);

    struct Node* current = table[index];
    struct Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found for deletion.\n");
        return;
    }

    if (prev == NULL) {
        table[index] = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Traverse and print all elements in the hash table
void traverseAndPrint() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = table[i];
        printf("Index %d:", i);
        while (current != NULL) {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, key;
    clrscr();
    initializeTable();

    while (1) {
        printf("Choose operation:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Traverse and Print\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter a key to search: ");
                scanf("%d", &key);
                if (search(key)) {
                    printf("Key found.\n");
                } else {
                    printf("Key not found.\n");
                }
                break;

            case 3:
                printf("Enter a key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;

            case 4:
                traverseAndPrint();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    getch();
    return 0;
}
