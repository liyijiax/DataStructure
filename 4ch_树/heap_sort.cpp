/*************************************************************************
	> File Name: heap_sort.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月19日 星期六 20时00分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __tmp; \
    __tmp = a; \
    a = b; \
    b = __tmp; \
}

void downUpdate(int *arr, int n, int ind) {
    while (ind << 1 <= n) {
        int tmp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[tmp] < arr[l]) swap(arr[l], arr[tmp]);
        if (r <= n && arr[tmp] < arr[r]) swap(arr[r], arr[tmp]);
        if (tmp == ind) break;
        swap(arr[tmp], arr[ind]);
        ind = tmp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i >= 1; i--) {
        swap(arr[1], arr[i]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    int *arr = (int *)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    output(arr, MAX_OP);
    free(arr);
    return 0;
}

