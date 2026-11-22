/*
 * SORTING AND SEARCHING - complete C demonstration
 * Compile: gcc sorting_searching.c -o sorting_searching
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void printIntArray(const int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

/* 1. MERGE SORT */
void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int *L = malloc((size_t)n1 * sizeof(int));
    int *R = malloc((size_t)n2 * sizeof(int));
    if (!L || !R) { free(L); free(R); fprintf(stderr, "Memory allocation failed\n"); exit(EXIT_FAILURE); }
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    free(L); free(R);
}
void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

/* 2. QUICK SORT */
int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            int t = a[++i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i + 1]; a[i + 1] = a[high]; a[high] = t;
    return i + 1;
}
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

/* 3. BUCKET SORT: input values must be in [0, 1). */
void insertionSortDouble(double a[], int n) {
    for (int i = 1; i < n; i++) {
        double key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}
void bucketSort(double a[], int n) {
    double **buckets = malloc((size_t)n * sizeof(double *));
    int *sizes = calloc((size_t)n, sizeof(int));
    if (!buckets || !sizes) { free(buckets); free(sizes); exit(EXIT_FAILURE); }
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc((size_t)n * sizeof(double));
        if (!buckets[i]) {
            for (int j = 0; j < i; j++) free(buckets[j]);
            free(buckets); free(sizes); exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < n; i++) {
        int index = (int)(n * a[i]);
        if (index == n) index = n - 1;
        buckets[index][sizes[index]++] = a[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        insertionSortDouble(buckets[i], sizes[i]);
        for (int j = 0; j < sizes[i]; j++) a[k++] = buckets[i][j];
        free(buckets[i]);
    }
    free(buckets); free(sizes);
}

/* 4. RADIX SORT: non-negative integers only. */
void countingSortDigit(int a[], int n, long long exp) {
    int output[MAX], count[10] = {0};
    for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (int)((a[i] / exp) % 10);
        output[--count[digit]] = a[i];
    }
    for (int i = 0; i < n; i++) a[i] = output[i];
}
void radixSort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];
    for (long long exp = 1; max / exp > 0; exp *= 10) {
        countingSortDigit(a, n, exp);
        if (exp > max / 10) break;
    }
}

/* 5. BUBBLE SORT */
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

/* 6. INSERTION SORT */
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}

/* 7. LINEAR SEARCH: returns index, or -1 if absent. */
int linearSearch(const int a[], int n, int key) {
    for (int i = 0; i < n; i++) if (a[i] == key) return i;
    return -1;
}

/* 8. BINARY SEARCH: array must be sorted in ascending order. */
int binarySearch(const int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(void) {
    int a[] = {8, 3, 7, 4, 2, 9};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int choice, key;
    printf("1 Merge Sort\n2 Quick Sort\n3 Bucket Sort\n4 Radix Sort\n");
    printf("5 Bubble Sort\n6 Insertion Sort\n7 Linear Search\n8 Binary Search\nChoice: ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 3) {
        double values[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
        int size = (int)(sizeof(values) / sizeof(values[0]));
        bucketSort(values, size);
        for (int i = 0; i < size; i++) printf("%.2f ", values[i]);
        printf("\n");
        return 0;
    }
    if (choice == 1) mergeSort(a, 0, n - 1);
    else if (choice == 2) quickSort(a, 0, n - 1);
    else if (choice == 4) radixSort(a, n);
    else if (choice == 5) bubbleSort(a, n);
    else if (choice == 6) insertionSort(a, n);
    else if (choice == 7 || choice == 8) {
        if (choice == 8) insertionSort(a, n);
        printf("Array: "); printIntArray(a, n);
        printf("Enter search key: ");
        if (scanf("%d", &key) != 1) return 1;
        int pos = choice == 7 ? linearSearch(a, n, key) : binarySearch(a, n, key);
        if (pos == -1) printf("Element not found\n");
        else printf("Element found at index %d\n", pos);
        return 0;
    } else {
        printf("Invalid choice\n");
        return 1;
    }
    printf("Sorted array: "); printIntArray(a, n);
    return 0;
}
