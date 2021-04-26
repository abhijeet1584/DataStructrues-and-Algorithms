#include <stdio.h>
#include <stdlib.h>

/* List
 * Store a given number of elements of a given data-type
 * Write/modify element at a position
 * Read element at a position
 */

/* ArrayList implementation
 * empty list has size 0
 * insert
 * remove
 * count
 * read/modify element at a position
 * Specify data type
 */

const char nl = '\n';

typedef enum {
    true = 1,
    false = 0
} boolean;

typedef struct {
    int size;
    int *array;
    int arraySize;
} ArrayList;

ArrayList* createArrayList() {
    ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
    list->size = 0;
    list->arraySize = 10;
    list->array = (int*) malloc(sizeof(int) * list->arraySize);
    printf("Array list created%c", nl);
    return list;
}

void cloneAndIncrease(ArrayList *list) {
    list->arraySize = list->size * 2;
    int *tempArr = (int*) malloc(sizeof(int) * list->arraySize);
    for (int counter = 0; counter < list->size; counter++)
        tempArr[counter] = list->array[counter];

    free(list->array);
    list->array = tempArr;
}

int get(ArrayList *list, int index) {
    // Index out of range exception
    if (index >= list->size || index < 0) {
        printf("List Index out of range%c", nl);
        return (int) '\0';
    }
    return list->array[index];
}

void print(ArrayList *list) {
    printf("[");
    for (int counter = 0; counter < list->size; counter++)
        printf("%d, ", get(list, counter));

    printf("\b\b]%c", nl);
}

void append(ArrayList *list, int data) {
    if (list->size + 1 > list->arraySize)
        cloneAndIncrease(list);

    list->array[list->size] = data;
    list->size++;
    printf("%d Added int List%c", data, nl);
}

void printArr(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b]\n");
}

void insert(ArrayList *list, int index, int data) {
    if (index >= list->size) {
        append(list, data);
        return;
    }
    if (list->size + 1 > list->arraySize)
        cloneAndIncrease(list);
    
    int *tempArr = (int*) malloc(sizeof(int) * (list->size - index));
    int j = 0;
    for (int i = index; i < list->size; i++) {
        tempArr[j] = list->array[i];
        j++;
    }
    list->array[index] = data;
    j = 0;
    for (int i = index + 1; i <= list->size; i++) {
        list->array[i] = tempArr[j];
        j++;
    }
    free(tempArr);
    list->size++;
    printf("%d added at index %d%c", index, data, nl);
}

int pop(ArrayList *list) {
    list->size--; // Since you cannot remove elements from an array
    return list->array[list->size - 1];
}

void removeElement(ArrayList *list, int index) {
    int tempArr[list->size - index + 1]; // getting the item just after the item at the given index
    int counter2 = 0;
    for (int counter = index + 1; counter < list->size; counter++) {
        tempArr[counter2] = list->array[counter];
        counter2++;
    }
    list->size--; // decreasing the size of the list
    counter2 = 0;
    for (int counter = index; counter < list->size; counter++) {
        list->array[counter] = tempArr[counter2];
        counter2++;
    }
}

void modify(ArrayList *list, int index, int data) {
    if (index >= list->size) {
        printf("List index out of range%c", nl);
        return;
    }
    list->array[index] = data;
    printf("Modified Index %d%c", index, nl);
    return;
}

int getSize(ArrayList *list) {
    return list->size;
}

int main(void) {
    ArrayList *list = createArrayList();
    while (true) {
        // Option menu
        printf("***** Array List *****%c", nl);
        printf("1. Append%c", nl);
        printf("2. Insert%c", nl);
        printf("3. Pop%c", nl);
        printf("4. Remove%c", nl);
        printf("5. Modify%c", nl);
        printf("6. Get%c", nl);
        printf("7. Print List%c", nl);
        printf("8. Exit%c", nl);
        printf("%c", nl);
        printf(">> ");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: {
            int data = 0;
            printf("Enter item value: ");
            scanf("%d", &data);
            append(list, data);
        } break;
        
        case 2: {
            int data, index;
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter item value: ");
            scanf("%d", &data);
            insert(list, index, data);
        } break;

        case 3: {
            printf("%d Popped from list%c", pop(list), nl);
        } break;

        case 4: {
            int index;
            printf("Enter index to remove: ");
            scanf("%d", &index);
            removeElement(list, index);
        } break;

        case 5: {
            int data, index;
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter item value: ");
            scanf("%d", &data);
            modify(list, index, data);
        } break;

        case 6: {
            int index;
            printf("Enter index: ");
            printf("INdex %d = %d%c", index, get(list, index), nl);
        } break;

        case 7: {
            print(list);
        } break;

        default:
            exit(0);
        }
        printf("%c", nl);
    }
}