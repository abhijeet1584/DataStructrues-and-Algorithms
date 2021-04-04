#include <stdio.h>
#include <stdlib.h>

const char nl = '\n';

/* Main Operations of Stack */
// push
// pop
// peek
// isEmpty

typedef struct
{
    int *arr;
    int size;
    int head;
    int capacity;
} Stack;

typedef enum
{
    true = 1,
    false = 0
} boolean;

Stack* createStack(int size)
{
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->arr = (int*) malloc(sizeof(int) * size);
    stack->head = -1;
    stack->size = 0;
    stack->capacity = size;
    return stack;
}

boolean isFull(Stack* stack)
{
    if (stack->head == stack->capacity - 1)
        return true;

    return false;
}

boolean isEmpty(Stack* stack)
{
    if (stack->head == -1)
        return true;

    return false;
}

void push(Stack* stack, int data)
{
    if (isFull(stack) == false)
    {
        stack->size++;
        stack->head++;
        stack->arr[stack->head] = data;
        printf("%d pushed to stack%c", data, nl);
    }
    else
        printf("Stack overflow%c", nl);
}

int pop(Stack* stack)
{
    if (isEmpty(stack) == false)
    {
        int temp = stack->arr[stack->head];
        stack->head--;
        stack->size--;
        printf("%d Popped from stack%c", temp, nl);
        return temp;
    }
    printf("Stack is empty%c", nl);
}

void items(Stack* stack)
{
    printf("[");
    for (int counter = stack->size - 1; counter >= 0; counter--)
        printf("%d, ", stack->arr[counter]);

    printf("\b\b]%c", nl);
}

int peek(Stack* stack)
{
    if (isEmpty(stack) == false)
        return stack->arr[stack->head];

    printf("Stack is empty%c", nl);
}

int main(void)
{
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);

    Stack* stack = createStack(size);

    while (true)
    {
        printf("****** MENU ******%c", nl);
        printf("1. push%c", nl);
        printf("2. pop%c", nl);
        printf("3. peek%c", nl);
        printf("4. isEmpty%c", nl);
        printf("5. isFull%c", nl);
        printf("6. items%c", nl);
        printf("7. deallocate%c", nl);
        printf("8. Quit%c", nl);
        printf("******************%c%c", nl, nl);

        int option = 0;
        printf(">>> ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            {
                printf("Item: ");
                int item = 0;
                scanf("%d", &item);
                push(stack, item);
            }
            break;

            case 2:
            {
                int p = pop(stack);
                printf("Popped item = %d%c", p, nl);
            }
            break;

            case 3:
            {
                int p = peek(stack);
                printf("Peeked item: %d%c", p, nl);
            }
            break;

            case 4:
            {
                if (isEmpty(stack))
                    printf("Stack is empty%c", nl);

                else
                    printf("Stack is NOT empty%c", nl);
            }
            break;

            case 5:
            {
                if (isFull(stack))
                    printf("Stack is full%c", nl);

                else
                    printf("Stack is NOT full%c", nl);
            }
            break;

            case 6:items(stack);
            break;

            case 7:
            {
                free(stack);
                printf("Stack deallocated from the memory%c", nl);
                return 0;
            }
            break;

            default:return 0;
        }
    }
}
