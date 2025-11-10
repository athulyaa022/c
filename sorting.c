#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp, count = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Steps (Bubble Sort): %d\n", count);
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, key, count = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            count++;
        }
        arr[j + 1] = key;
    }
    printf("Steps (Insertion Sort): %d\n", count);
}

// Quick Sort
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int *count) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        (*count)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *count) {
    if (low < high) {
        int pi = partition(arr, low, high, count);
        quickSort(arr, low, pi - 1, count);
        quickSort(arr, pi + 1, high, count);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r, int *count) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        (*count)++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r, int *count) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {5, 3, 8, 4, 2};
    int n = 5;

    printf("Original Array: ");
    printArray(arr1, n);

    int arr2[5], arr3[5], arr4[5];
    for (int i = 0; i < n; i++) {
        arr2[i] = arr3[i] = arr4[i] = arr1[i];
    }

    bubbleSort(arr1, n);
    insertionSort(arr2, n);

    int countQuick = 0;
    quickSort(arr3, 0, n - 1, &countQuick);
    printf("Steps (Quick Sort): %d\n", countQuick);

    int countMerge = 0;
    mergeSort(arr4, 0, n - 1, &countMerge);
    printf("Steps (Merge Sort): %d\n", countMerge);

    return 0;
}