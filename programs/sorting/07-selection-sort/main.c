/* Selection Sort - Standalone C program */
#include <stdio.h>
int main(void) {
    int a[1000], n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) return 1;
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        int temp = a[i]; a[i] = a[min]; a[min] = temp;
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}