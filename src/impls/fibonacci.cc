#include <stdio.h>
#include <assert.h>
#include "../header.h"

int fibonacci_rec(int n) {
    if (n == 0 || n ==1) return n;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int fibonacci_it(int n) {
    if (n == 0 || n ==1) return n;

    int prev = 1, prev_prev = 0, res = 0;
    for (int i = 2;i <= n;i++) {
        res = prev + prev_prev;
        prev_prev = prev;
        prev = res;
    }

    return res;
}

void test_fibonacci () {
    for (int i = 0;i < 100;i++) {
        printf("i = %d, it = %d, rec = %d\n", i, fibonacci_it(i), fibonacci_rec(i));
        assert(fibonacci_it(i) == fibonacci_rec(i));
    }
    return;
}