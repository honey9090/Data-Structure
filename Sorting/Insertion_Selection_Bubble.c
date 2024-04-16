#include <stdio.h>

void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr_insertion[] = { 12, 11, 13, 5, 6 };
    int arr_selection[] = { 64, 25, 12, 22, 11 };
    int arr_bubble[] = { 34, 12, 24, 9, 5 };

    int n_insertion = sizeof(arr_insertion) / sizeof(arr_insertion[0]);
    int n_selection = sizeof(arr_selection) / sizeof(arr_selection[0]);
    int n_bubble = sizeof(arr_bubble) / sizeof(arr_bubble[0]);

    printf("Insertion Sort:\n");
    insertionSort(arr_insertion, n_insertion);
    printArray(arr_insertion, n_insertion);

    printf("\nSelection Sort:\n");
    selectionSort(arr_selection, n_selection);
    printArray(arr_selection, n_selection);

    printf("\nBubble Sort:\n");
    bubbleSort(arr_bubble, n_bubble);
    printArray(arr_bubble, n_bubble);

    return 0;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}