#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int table[TABLE_SIZE];

// Initialize the hash table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }
}

// Hash function to determine the index in the table
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Probe function for linear probing
int linearProbe(int index, int i) {
    return (index + i) % TABLE_SIZE;
}

// Insert a value into the hash table using linear probing
void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int probeIndex = linearProbe(index, i);

        if (table[probeIndex] == -1) {
            table[probeIndex] = key;
            return;
        } else {
            i++;
        }
    }

    printf("Table is full. Unable to insert key %d.\n", key);
}

// Search for a value in the hash table using linear probing
int search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int probeIndex = linearProbe(index, i);

        if (table[probeIndex] == key) {
            return 1; // Found
        } else if (table[probeIndex] == -1) {
            return 0; // Not found
        } else {
            i++;
        }
    }

    return 0; // Not found
}

// Delete a value from the hash table using linear probing
void delete(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int probeIndex = linearProbe(index, i);

        if (table[probeIndex] == key) {
            table[probeIndex] = -1;
            return;
        } else if (table[probeIndex] == -1) {
            printf("Key not found for deletion.\n");
            return;
        } else {
            i++;
        }
    }

    printf("Key not found for deletion.\n");
}

// Traverse and print all elements in the hash table
void traverseAndPrint() {
    printf("Hash table elements:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != -1) {
            printf("Index %d: %d\n", i, table[i]);
        }
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
