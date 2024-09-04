#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
       swap(&arr[j + 1], &key);
    }
}

// Function to print the array
void printarray(int arr[], int n) {
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[100],n;
    printf("enter the size of the array: ");
    scanf("%d", &n);

    printf("enter the elements of the array: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int sortmethod;
    printf("enter 1 for bubble sort.\n");
    printf("enter 2 for selection sort.\n");
    printf("enter 3 for insertion sort.\n");
    scanf("%d", &sortmethod);

    switch(sortmethod)
    {
    case 1:
        printf("bubble sort: \n");
        bubbleSort(arr,n);
        printarray(arr,n);
        break;
    case 2:
         printf("selection sort: \n");
       selectionSort(arr,n);
        printarray(arr,n);
        break;
    case 3:
        printf("insertion sort: \n");
        insertionSort(arr,n);
        printarray(arr,n);
        break;
    default:
        printf("invalid input enter '1'or'2'or'3'");
    }
    return 0;
}
