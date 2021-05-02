#include <stdio.h>
#include <stdlib.h>

/** Properties
 * First in first out 
 */

/** Functions
 * push(); to push an item on top
 * pop(); to remove an item from the top
 * peek(); return the value wihout removing the 
 * empty(); it returns true if nothing is on the top os the stack, else returns false
 * search(); searches the stack
 * clear(); clears the stack
 * printElements(); 
 * size(); return the size of the stack
 * remove();
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

// ==================================
// STACK FUNTIONS
// ==================================

typedef struct {
    int size;
    LinkedList *list;
} Stack;

Stack* createStack() {
    Stack *stack = (Stack*) malloc(sizeof(stack));
    LinkedList *list = createLinkedList();
    stack->list = list;
    return stack;
}

void push(Stack *stack, int data) {
    add(stack->list, 0, data);
    printf("%d Pushed to the stack%c", data, nl);
    stack->size++;
}

int stackPop(Stack *stack) {
    int d = get(stack->list, 0);
    removeItem(stack->list, 0);
    printf("%d popped from stack%c", d, nl);
    stack->size--;
    return d;
}

int peek(Stack *stack) {
    int data = get(stack->list, 0);
    return data;
}

void empty(Stack *stack) {
    for (int counter = stack->list->size - 1; counter >= 0; counter--) {
        removeItem(stack->list, counter);
        stack->size--;
    }
}

int search(Stack *stack, int query) {
    for (int counter = 0; counter < stack->size; counter++) {
        if (get(stack->list, counter) == query)
            return counter;
    }
}

int main(void) {
    Stack *stack = createStack();
    while (true) {
        printf("***** STACK FUNCTIONS *****%c", nl);
        printf("1. Push%c", nl);
        printf("2. Pop%c", nl);
        printf("3. Peek%c", nl);
        printf("4. Search%c", nl);
        printf("5. Print Stack%c", nl);
        printf("6. Unallocate%c", nl);
        printf("7. exit%c", nl);

        int choice = 0;
        printf("%c>>", nl);
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int data = 0;
                printf("Enter data: ");
                scanf("%d", &data);
                add(stack->list, 0, data);
            } break;

            case 2: {
                stackPop(stack);
            } break;

            case 3: {
                printf("Peeked element = %d%c", peek(stack), nl);
            } break;

            case 4: {
                int query = 0;
                printf("Enter element to search: ");
                scanf("%d", &query);
                printf("Index = %d%c", search(stack, query), nl);
            } break;

            case 5: {
                print(stack->list);
            } break;

            case 6: {
                empty(stack);
                printf("Stack unallocated from main memory%c", nl);
                return 0;
            } break;

            default: return 0;
        }
        printf("%c", nl);
    }
}