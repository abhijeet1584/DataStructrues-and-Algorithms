#include <stdio.h>
#include <stdlib.h>

/** Properties
 * The first node of the linked list is called the head of the linked list
 * the last node of the linked list is pointing to NULL
 * Linked lists are not stored at contiguous memory locations
 * Dynamic in nature
 */

/** Functions
 * Creating
 * Adding to the end of the list
 * Removing from the end of the list
 * Removing from the beginning of the list
 * Add to the beginning of the list
 * Retrieve a node by its position in the list
 * Change the value of a node given its position in the list and value
 * Add a new node to the list at a specified position
 */

const char nl = '\n';

typedef enum {
    true = 1,
    false = 0
} boolean;

typedef struct Node {
    int data;
    struct Node *next; 
} Node;

typedef struct {
    int size;
    Node *head; // first node of the list
    Node *tail; // last node of the list
} LinkedList;

// Creating the Linked list
LinkedList* createLinkedList() {
    LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
    list->size = 0;
}

// checking if the linked list is empty
boolean isEmpty(LinkedList *list) {
    if (list->head == NULL)
        return true;
    
    return false;
}

// Adding element at the last of the Linked list
void append(LinkedList *list, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (isEmpty(list)) {
        list->head = node;
        printf("%d Added to list%c", data, nl);
        list->tail = list->head;
        list->size++;
        return;
    } else {
        Node *temp = list->tail;
        temp->next = node;
        list->tail = node;
        list->size++;
        printf("%d Added to list%c", data, nl);
        return;
    }
}

// Printing all the elements of the Linked list
void print(LinkedList *list) {
    Node *temp = list->head;
    printf("[");
    while (temp != NULL) { 
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\b\b]%c", nl);
}

// Getting the node at a specific index
Node* getNode(LinkedList *list, int index) {
    if (index >= list->size && index < 0) {
        printf("List index out of range%c", nl);
        return NULL;
    }

    Node *node = list->head;
    for (int counter = 1; counter <= index; counter++)
        node = node->next;

    return node;
}

// Getting the value stored at an index
int get(LinkedList *list, int index) {
    Node *node = getNode(list, index);
    return node->data;
}

// removing item from the mid or start of the Linked list
void removeItem(LinkedList *list, int index) {
    if (index == 0) {
        Node *n = getNode(list, 1);
        Node *rem = getNode(list, 0); // rem = remove
        list->head = n;
        free(rem);
        list->size--;
        return;
    } 
    Node *prev = getNode(list, index - 1);
    Node *next = getNode(list, index + 1);
    Node *n = getNode(list, index);
    prev->next = next;
    list->size--;
    free(n);

    // setting new tail
    list->tail = getNode(list, list->size - 1);
}

// Adding element in the middle of the list
void add(LinkedList *list, int index, int data) {
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = data;
    if (index == 0) {
        Node *temp = list->head;
        new->next = temp;
        list->head = new;
        list->size++;
        return;
    }
    new->next = getNode(list, index);
    Node *next = getNode(list, index - 1); // next for the next node which is after the given index
    next->next = new;
    list->size++;

    // setting tail
    Node *last = getNode(list, list->size-1);
    list->tail = last;
    printf("%d Added on index %d%c", new->data, index, nl);
}

// Removing node from the last
void pop(LinkedList *list) {
    removeItem(list, list->size - 1);
}

// Change the value of a specific node, using the index
void changeValue(LinkedList *list, int index, int data) {
    Node *node = getNode(list, index);
    node->data = data;
}

// making printf easier
void println(char *string) {
    printf("%s%c", string, nl);
}

int main(void) {
    LinkedList *list = createLinkedList();
    while (true) {
        println("***** LINKED LIST ******");
        println("1. Append");
        println("2. Pop");
        println("3. Remove");
        println("4. Add");
        println("5. Get");
        println("6. Change value of a node");
        println("7. Print List");
        println("8. Exit");
        printf(">> ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: {
            int data = 0;
            printf("Element value: ");
            scanf("%d", &data);
            append(list, data);
        } break;
        
        case 2: { 
            pop(list);
        } break;

        case 3: {
            int index = 0;
            printf("Index: ");
            scanf("%d", &index);
            removeItem(list, index);
        } break;

        case 4: {
            int data, index;
            printf("Index: ");
            scanf("%d", &index);
            printf("Data: ");
            scanf("%d", &data);
            add(list, index, data);
        } break;

        case 5: {
            int index = 0;
            printf("Index: ");
            scanf("%d", &index);
            printf("%d%c", get(list, index), nl);
        } break;

        case 6: {
            int data, index;
            printf("Index: ");
            scanf("%d", &index);
            printf("New Value: ");
            scanf("%d", &data);
            changeValue(list, index, data);
        } break;

        case 7: {
            print(list);
        } break;

        default: return 0;
        }
    }
    println("");
}