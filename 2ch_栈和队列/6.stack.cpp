/*************************************************************************
	> File Name: 5.stack.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月05日 星期六 18时09分54秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct Stack {
    int *data;
    int top, size;
}Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) return 0;
    s->top++;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top--;
    return 1;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void output(Stack *s) {
    int flag = 0;
    printf("Stack = [");
    for (int i = s->top; i >= 0; i--) {
        flag && printf(", ");
        printf("%d", s->data[i]);
        flag = 1;
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    Stack *s = init(max_op);
    int op, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to Stack = %d\n", val, push(s, val));
                output(s);
                printf("\n");
            }
            case 3: {
                printf("pop %d from the Stack = %d\n", top(s), pop(s));
                output(s);
                printf("\n");
            }
        }
    }    
    clear(s);
    return 0;
}
