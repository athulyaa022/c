#include <stdio.h>
#include <stdlib.h>

struct Block {
    int size;
    int free;
    struct Block *next;
    struct Block *prev;
};

struct Block *head = NULL;

// Create initial memory blocks
void createMemory(int blocks[], int n) {
    struct Block *temp, *newBlock;
    head = (struct Block *)malloc(sizeof(struct Block));
    head->size = blocks[0];
    head->free = 1;
    head->prev = NULL;
    head->next = NULL;
    temp = head;

    for (int i = 1; i < n; i++) {
        newBlock = (struct Block *)malloc(sizeof(struct Block));
        newBlock->size = blocks[i];
        newBlock->free = 1;
        newBlock->prev = temp;
        newBlock->next = NULL;
        temp->next = newBlock;
        temp = newBlock;
    }
}

// Allocate memory
void allocate(int size) {
    struct Block *temp = head;
    while (temp != NULL) {
        if (temp->free && temp->size >= size) {
            temp->free = 0;
            printf("Allocated %d bytes.\n", size);
            return;
        }
        temp = temp->next;
    }
    printf("No sufficient memory available!\n");
}

// Free memory
void freeBlock(int size) {
    struct Block *temp = head;
    while (temp != NULL) {
        if (!temp->free && temp->size == size) {
            temp->free = 1;
            printf("Freed %d bytes.\n", size);
            return;
        }
        temp = temp->next;
    }
    printf("Block not found.\n");
}

// Garbage Collection
void garbageCollect() {
    struct Block *temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->free && temp->next->free) {
            temp->size += temp->next->size;
            struct Block *toDelete = temp->next;
            temp->next = toDelete->next;
            if (temp->next != NULL)
                temp->next->prev = temp;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }
    printf("Garbage Collection Done.\n");
}

// Display Memory
void displayMemory() {
    struct Block *temp = head;
    printf("\nMemory Blocks:\n");
    printf("----------------------\n");
    while (temp != NULL) {
        printf("Block Size: %d\tStatus: %s\n", temp->size, temp->free ? "Free" : "Allocated");
        temp = temp->next;
    }
    printf("----------------------\n");
}

int main() {
    int blocks[] = {100, 200, 300, 400};
    int n = 4;
    createMemory(blocks, n);
    displayMemory();

    allocate(200);
    allocate(100);
    displayMemory();

    freeBlock(200);
    garbageCollect();
    displayMemory();

    return 0;
}