#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char nl = '\n';

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int *arr, int size)
{
    printf("[");
    for (int counter = 0; counter < size; counter++)
        printf("%d, ", arr[counter]);

    printf("\b\b]%c", nl);
}

void bubbleSort(int *arr, int size)
{
    for (int x = 0; x < size - 1; x++)
    {
        for (int y = 0; y < size - x - 1; y++)
        {
            if (arr[y] > arr[y+1])
                swap(&arr[y], &arr[y+1]);
        }
    }
}

int* getArray(int size)
{
    int *array = (int*) malloc(sizeof(int) * size);
    for (int counter = 0; counter < size; counter++)
    {
        printf("Index %d = ", counter);
        scanf("%d", &array[counter]);
    }
    return array;
}

int main(void)
{
    printf("Enter size: ");
    int size = 0;
    scanf("%d", &size);
    int *arr = getArray(size);
    // int arr[size]; only used when time_taken is caluclated
    int temp = 0;
    // for (int counter = size; counter >= 0; counter--)
    // {
    //     arr[temp] = counter;
    //     temp++;
    // }

    printf("Unsorted --> ");
    printArray(arr, size);

    // clock_t t;
    // t = clock();
    bubbleSort(arr, size);
    // t = clock() - t;
    // float time_taken = ((double)t)/CLOCKS_PER_SEC;
    // printf("Time taken by bubble Sort = %f%c", time_taken, nl);

    printf("Sorted --> ");
    printArray(arr, size);
}
