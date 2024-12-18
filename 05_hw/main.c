#include "stack.h"
#include <assert.h>
#include <stdio.h>

void test_stack_operations() {
    printf("Start of testing\n");
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);
    printf("The initial stack\n");
    traverseStack(&stack);
    push(&stack, 10);
    assert(stack.top->data == 10);
    push(&stack, 20);
    push(&stack, 30);

    assert(isEmpty(&stack) == false);
    printf("Stack after adding elements\n");
    traverseStack(&stack);
    assert(getTop(&stack)->data == 30);
    assert(pop(&stack) == true);
    printf("Stack after excluding the last element\n");
    traverseStack(&stack);


    assert(getTop(&stack)->data == 20);

    assert(searchByValue(&stack, 20) != NULL);
    assert(searchByValue(&stack, 100) == NULL);

    assert(searchByIndex(&stack, 0)->data == 20);
    assert(searchByIndex(&stack, 1)->data == 10);
    assert(searchByIndex(&stack, 2) == NULL);

    destroyStack(&stack);
    assert(isEmpty(&stack) == true);
    printf("End of testing\n");
}

int main() {
    test_stack_operations();
    printf("All tests passed!\n");

    return 0;
}


