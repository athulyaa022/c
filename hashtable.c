#include <stdio.h>

#define SIZE 10  // Hash table size

// Safe hash function that handles negative keys too
int hashFunction(int key) {
    int idx = key % SIZE;
    if (idx < 0) idx += SIZE;
    return idx;
}

int main() {
    int hashTable[SIZE];
    int i, n, key, index;
    int inserted = 0;

    // Initialize hash table with -1 (indicates empty)
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements (max %d): ", SIZE);
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) {
        printf("Nothing to insert.\n");
        return 0;
    }

    if (n > SIZE) {
        printf("Warning: you asked to insert %d elements but table size is %d.\n", n, SIZE);
        printf("Only the first %d insertions will be attempted.\n", SIZE);
        n = SIZE;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &key) != 1) break;

        if (inserted == SIZE) {
            printf("Hash table is full — cannot insert more elements.\n");
            break;
        }

        index = hashFunction(key);

        // Linear probing in case of collision, stop if we've looped all slots
        int start = index;
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == start) break; // we've probed all slots
        }

        if (hashTable[index] == -1) {
            hashTable[index] = key;
            inserted++;
        } else {
            // table full
            printf("Could not insert %d: table is full.\n", key);
        }
    }

    // Display hash table
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d -> %d\n", i, hashTable[i]);
        else
            printf("Index %d -> EMPTY\n", i);
    }

    return 0;
}
