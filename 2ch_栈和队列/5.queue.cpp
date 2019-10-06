/*************************************************************************
	> File Name: 4.queue.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月05日 星期六 15时48分17秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct Queue {
    int *data;
    int head, tail, length, count;
}Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->count = 0;
    q->length = n;
    return q;
}

int empty(Queue *q) {
    return q->count == 0;

}

void expand(Queue *q) {
    q->length *= 2;
    q->data = (int *)realloc(q->data, sizeof(int) * q->length);
    for (int j = 0, i = q->head; j < q->count; j++) {
        q->data[q->count + j] = q->data[(i + j) % q->count];
    }
    q->head = q->count;
    q->tail = 0;
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->count == q->length) {
        expand(q);
    }
    q->data[q->tail] = val;
    q->tail = (q->tail + 1) % q->length;
    q->count++;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head = (q->head + 1) % q->length;
    q->count--;
    return 1;
}

int front(Queue *q) {
    if (q == NULL) return 0;
    return q->data[q->head];
}

void output(Queue *q) {
    printf("Queue(%d) = [", q->count);
    for (int i = q->head, j = 0; j < q->count; j++) {
        j && printf(", ");
        printf("%d", q->data[(i + j) % q->length]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Queue *q = init(5);
    int op, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to Queue = %d\n", val, push(q, val));
                output(q);
                printf("\n");
            } break;
            case 3: {
                //printf("pop\n");
                //printf("%d\n", front(q));
                //output(q);
                printf("pop %d from Queue = %d\n", front(q), pop(q));
                output(q);
                printf("\n");
            } break;
        }
    }
    clear(q);
    return 0;
} // 加个扩容
// 如果是奇怪的问题，很可能就是哪个函数参数写错了，没有写正常。比如realloc
// 没有写好开的空间大小
// 内存泄露，操作系统还以为是你家的
// 多类型数组，用结构体存不同类型字段
// int和double的最大值string排序vector容器。栈队列
// 多想多看，不然长不成参天大树，长成电线杆
// 学c++能不写c就别写，虽然觉得面向过程很爽，面向对象能力才有，克制自己
// 这时候暂时吧c忘掉，不要想着当前功能，抽象成一个类，从定向问题，变成解决
// 一类问题。如果只是单个问题写代码，只是一时爽。但是饭要一口口吃，数据结构
// 都不明白，今后根本抽闲不出来。看的太远会很累，每一步走踏实就好
// 现在跟着海贼走就行，不要打鸡血，保持好节奏，劳逸结合
// 劳逸结合，长期来看，这就是最快的了，这样才能走远
// 走踏实，不然走的越远，死的越快，南辕北辙
