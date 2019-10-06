/*************************************************************************
	> File Name: 8.栈的复习.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月06日 星期日 10时14分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
    int size, top;
    int *data;
} Stack;

void init(Stack *s, int size) {
    s->size = size;
    s->top = -1;
    s->data = (int *)malloc(sizeof(char) * s->size);
}

int push(Stack *s, int val) {
    if (s->top + 1 >= s->size) return 0;
    s->top++;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (s->top == -1) return 0;
    s->top--;
    return 1;
}

int top(Stack *s) {
    return s->data[s->top];
}

int empty(Stack *s) {
    if (s == NULL) return 0;
    return s->top == -1;
}

int precede(char a, char b) {
    if ((a == '*' || a == '/') && (b == '+' || b == '-')) {
        return 1;
    } else {
        return 0;
    }
}
int operate(int a, int b, char ch) {
    if (ch == '+') {
        return a + b;
    } else if (ch == '-') {
        return a - b;
    } else if (ch == '*') {
        return a * b;
    } else {
        return a / b;
    }
}

void calc(Stack *numbers, Stack *operators) {
    int a = top(numbers);
    pop(numbers);
    int b = top(numbers);
    pop(numbers);
    int c = operate(b, a, top(operators));
    pop(operators);
    push(numbers, c);
    return ;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
	int n;
    scanf("%d", &n);
    Stack *numbers = (Stack *)malloc(sizeof(Stack));
    Stack *operators = (Stack *)malloc(sizeof(Stack));
    init(numbers, n);
    init(operators, n);
    char *buffer = (char *)malloc(sizeof(char) * n);
    scanf("%s", buffer);
    int i = 0;
    while (i < n) {
    if (isdigit(buffer[i])) {
		push(numbers, buffer[i] - '0');
        i++;
    } else {
        if (empty(operators) || precede(buffer[i], top(operators))) {
            push(operators, buffer[i]);
            i++;
        } else {
            calc(numbers, operators);
        }
    } 
    }
    while (!empty(operators)) {
        calc(numbers, operators);
    }
    printf("%d\n", top(numbers));
    clear(numbers);
    clear(operators);
    free(buffer);
    return 0;
}
