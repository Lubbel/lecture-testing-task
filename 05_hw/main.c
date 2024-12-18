#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>

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

// Функция для измерения времени выполнения push
void benchmark_push(Stack* stack, int num_operations) {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Засекаем время начала
    for (int i = 0; i < num_operations; i++) {
        push(stack, i); // Выполняем push
    }
    end = clock(); // Засекаем время окончания

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Push benchmark: %d operations took %f seconds\n", num_operations, cpu_time_used);
}

// Функция для измерения времени выполнения pop
void benchmark_pop(Stack* stack, int num_operations) {
    clock_t start, end;
    double cpu_time_used;

    // Предварительно заполняем стек
    for (int i = 0; i < num_operations; i++) {
        push(stack, i);
    }

    start = clock(); // Засекаем время начала
    for (int i = 0; i < num_operations; i++) {
        pop(stack); // Выполняем pop
    }
    end = clock(); // Засекаем время окончания

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Pop benchmark: %d operations took %f seconds\n", num_operations, cpu_time_used);
}

int main() {
    test_stack_operations();
    printf("All tests passed!\n");

    Stack stack;
    initStack(&stack);

    int num_operations = 1000000; // Количество операций

    // Бенчмарк push
    benchmark_push(&stack, num_operations);

    // Бенчмарк pop
    benchmark_pop(&stack, num_operations);

    destroyStack(&stack);

    return 0;
}


