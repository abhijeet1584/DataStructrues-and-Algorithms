#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

const char nl = '\n';

void printArray(int array[], int size)
{
    printf("[");
    for (int counter = 0; counter < size; counter++)
        printf("%d, ", array[counter]);

    printf("\b\b]\n");
}

void merge(int *A, int *L, int *R, int leftCount, int rightCount)
{
    int i = 0, j = 0, k = 0;
    // i- to mark the index of left subarray (L)
    // j- to mark the index of right subarray (R)
    // k- to mark the index of merged subarray (R)

    while (i < leftCount && j < rightCount)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            k++;
            i++;
        }
        else
        {
            A[k] = R[j];
            k++;
            j++;
        }
    }
    while (i < leftCount)
    {
        A[k] = L[i];
        k++;
        i++;
    }
    while (j < rightCount)
    {
        A[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int size)
{
    int mid, *L, *R;
    if (size < 2)
        return; // base condition

    mid = size / 2;

    L = (int*) malloc(mid * sizeof(int));
    R = (int*) malloc((size - mid) * sizeof(int));

    for (int counter  = 0; counter < mid; counter++)
        L[counter] = arr[counter];

    for (int counter = mid; counter < size; counter++)
        R[counter - mid] = arr[counter];

    mergeSort(L, mid);
    mergeSort(R, size-mid);
    merge(arr, L, R, mid, size-mid);
    free(L);
    free(R);
}

int* getArray(int size)
{
    int *arr;
    arr = (int*) malloc(sizeof(int) * size);
    for (int counter = 0; counter < size; counter++)
    {
        printf("Index %d: ", counter);
        scanf("%d", &arr[counter]);
    }
    return arr;
}

int main(void)
{
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    // int arr[size]; only used when calculating time_taken
    int *arr;
    arr = getArray(size);

    // int temp = 0;
    // for (int counter = size; counter >= 0; counter--)
    // {
    //     arr[temp] = counter;
    //     temp++;
    // }

    printf("Unsorted --> ");
    printArray(arr, size);

    // clock_t t;
    // t = clock();
    mergeSort(arr, size);
    // t = clock() - t;
    // float time_taken = ((double)t)/CLOCKS_PER_SEC;
    // printf("Time taken by merge Sort = %f%c", time_taken, nl);

    printf("Sorted --> ");
    printArray(arr, size);
}
