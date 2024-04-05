#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct stack {
    int *arr;
    int top;
} stack;

void push(stack *stack, int e) {
    stack->arr[++stack->top] = e;
    return;
}

int pop(stack *stack) {
    return stack->arr[stack->top--];
}

void move(stack *src, stack *des, stack *another, int len) {
    if (len == 1) {
        push(des, pop(src));
        return;
    }
    if (len > 1) {
        move(src, another, des, len - 1);
        move(src, des, another, 1);
        move(another, des, src, len - 1);
    }
}

void hanota(int* A, int ASize, int* &C, int &CSize){
    stack sA, sB, sC;
    sA.top = ASize - 1;
    sA.arr = A;

    sB.top = -1;
    sB.arr = (int *)malloc(100);

    sC.top = -1;
    sC.arr = (int *)malloc(100);

    move(&sA, &sC, &sB, ASize);
    free(sB.arr);

    C = sC.arr;
    CSize = sC.top + 1;
}

void test_hanoi() {
    int A[] = {5, 4, 3, 2, 1}, B[] = {5, 4, 3, 2, 1}, *C, CSize;

    hanota(A, 5, C, CSize);

    for(int i = 0;i < CSize;i++) {
        assert(C[i] == B[i]);
    }

    return;
}