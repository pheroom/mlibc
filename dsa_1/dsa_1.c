#include <stdio.h>
#include <time.h>
#include "dsa_1_sorts.h"
#include "dsa_1_hashmap.h"
#include "dsa_1_stack.h"

int isPrime(int n){
    for (int i = 2; i*i <= n; ++i) {
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int *sieveEratosthenes(int n){
    int sieve[n];
    for(int i = 2; i*i < n; i++){
        if(sieve[i]) continue;
        for (int j = i*i; j < n; j += i) {
            sieve[j] = sieve[j] || j+1 % i == 0;
        }
    }
    return sieve;
}

int *max(int *a, int size){
    int *mx = &*a++;
    int *cur;
    while(--size){
        cur = &*a++;
        if(*cur > *mx) mx = cur;
    }
    return mx;
}

int *min(int *a, int size){
    int *mn = &*a++;
    int *cur;
    while(--size){
        cur = &*a++;
        if(*cur < *mn) mn = cur;
    }
    return mn;
}

int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

double power(double a, int n){
    if(n == 0) return 1;
    if(n % 2 == 0) return power(a*a, n/2);
    return a * power(a, n-1);
}

int fib(int n){
    int a[n+1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}

int main() {
    Stack *stack = ST_create(10);
    ST_push(stack, 1);
    ST_push(stack, 2);
    ST_push(stack, 3);
    printf("-- %d -- \n", ST_pop(stack));
    ST_push(stack, 4);
    printf("-- %d -- / %d / \n", ST_peek(stack), stack->top);
    ST_free(stack);
    
    HashMap *map = HM_create(10);
    HM_insert(map, 179, 137);
    HM_insert(map, 15, 125689);
    HM_insert(map, 125896, 258);
    HM_remove(map, 15);
    int v1 = HM_lookup(map, 179);
    int v2 = HM_lookup(map, 14);
    int v3 = HM_lookup(map, 125896);
    HM_free(map);
    printf("-- %d %d %d --\n", v1, v2, v3);

    clock_t time1 = clock();
    printf("gcd : %d\n", gcd(36, 9));
    printf("fact : %d\n", factorial(6));
    printf("pow : %d\n", (int) power(2, 4));
    printf("fib : %d\n", fib(46));
    clock_t time2 = clock();
    int deltaTime = (time2 - time1) * 1000 / CLOCKS_PER_SEC;
    printf("delta : %d ms\n", deltaTime);

    int nn = 9;
    int arr[] = {1, 0, 7, 6, 3, 1, 0 ,1, 9};
    bubbleSort(arr, &nn);
    for (int i = 0; i < nn; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}