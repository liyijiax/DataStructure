/*************************************************************************
	> File Name: priority_queue.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月19日 星期六 18时08分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b; \
    b = __tmp; \
}

typedef struct priority_queue {
    int *data;
    int size, cnt;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q->cnt == q->size) return 0;
    q->data[++q->cnt] = val;
    //printf("push %d\n", val);
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (empty(q)) return 0;
    swap(q->data[1], q->data[q->cnt]); // 切记引用成员变量协商结构体名字和指针
    q->cnt--; // 用宏的时候不要写--，这里就展开时就多减了
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[ind] < q->data[l]) temp = l;
        if (r <= q->cnt && q->data[temp] < q->data[r]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    priority_queue *q = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        push(q, val);
    }
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    for (int i = 1; i <= MAX_OP; i++) {
        printf("%d ", q->data[i]);
        pop(q);
    }
    printf("\n");
    clear(q);
    return 0;
}
