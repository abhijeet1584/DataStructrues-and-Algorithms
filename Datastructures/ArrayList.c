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

// Boolean values
typedef enum {
	true = 1,
	false = 0
} boolean;

typedef struct {
	int size;
	int *array;
	int arrSize;
} ArrayList;

ArrayList* createList() {
	int defaultSize = 10;
	ArrayList *array = (ArrayList*) malloc(sizeof(ArrayList));
	array->size = 0;
	array->array = (int*) malloc(sizeof(int) * defaultSize);
	array->arrSize = defaultSize;
	return array;
}

void clone(ArrayList *list) {
	int size = list->arrSize * 2;
	int *newArr = (int*) malloc(sizeof(int) * size);
	for (int i = 0; i < size/2; i++)
		newArr[i] = list->array[i];
	free(list->array);
	list->array = newArr;
	list->arrSize = size;
}

void addAtLast(ArrayList *list, int data) {
	if (list->size == list->arrSize) 
		clone(list);
	
	list->array[list->size] = data;
	list->size++;
}

int get(ArrayList *list, int index) {
	if (index >= list->size) {
		printf("List Index out of range");
		return (int)'\0';
	} else {
		return list->array[index];
	}
}

void add(ArrayList *list, int index, int data) {
	if (index >= list->size) {
		addAtLast(list, data);
		return;
	}
	if (list->size + 1 > list->arrSize)
		clone(list);
	
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
}

void print(ArrayList *list) {
	printf("[");
	for (int counter = 0; counter < list->size; counter++) 
		printf("%d, ", get(list, counter));

	printf("\b\b]\n");
}

void removeElement(ArrayList *list, int index) {
	int *tempArr = (int*) malloc(sizeof(int) * (list->size - index));
	int counter2 = 0;
	for (int counter = index + 1; counter < list->size; counter++) {
		tempArr[counter2] = list->array[counter];
		counter2++;
	}
	counter2 = 0;
	for (int counter = index; counter < list->size - 1; counter++) {
		list->array[counter] = tempArr[counter2];
		counter2++;
	}
	list->size--;
	free(tempArr);
}

void pop(ArrayList *list) {
	removeElement(list, list->size - 1);
}

int main(void) {
	ArrayList *list = createList();
	while (true) {
		printf("***** ArrayList *****\n");
		printf("1. Append\n");
		printf("2. add\n");
		printf("3. pop\n");
		printf("4. remove\n");
		printf("5. size\n");
		printf("6. Print List\n");
		printf("7: exit\n\n");
		printf(">> ");
		int choice;
		scanf("%d", &choice);
		switch(choice) {
			case 1: { 
						printf("Enter item: ");
						int data = 0;
						scanf("%d", &data);
						addAtLast(list, data);
						printf("%d Appended to list\n", data);
					}
					break;

			case 2: {
						printf("Enter item: ");
						int data = 0;
						scanf("%d", &data);
						int index;
						printf("Enter index: ");
						scanf("%d", &index);
						add(list, index, data);
						printf("%d Added to list\n", data);
					}
					break;

			case 3: {
						pop(list);
						printf("Last element popped\n");
					}
					break;

			case 4: {
						printf("Enter index: ");
						int index;
						scanf("%d", &index);
						removeElement(list, index);
						printf("Index %d removed\n", index);
					}
					break;

			case 5: printf("Size of ArrayList = %d\n", list->size);
					break;

			case 6: print(list);
					break;
			
			case 7: return 0;

			default: break;
		}
		printf("\n");
	}
	return 0;
}
