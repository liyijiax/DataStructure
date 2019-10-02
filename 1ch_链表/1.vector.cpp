/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月02日 星期三 15时14分30秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

typedef struct Vector {
    int *data;
    int size, length;
}Vector;

Vector *init(int n) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

int expand(Vector *v) {
    int extr_size = v->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));
        if (p) break;
        extr_size >>= 1;
    }
    if (p == NULL) return 0;
    v->size += extr_size;
    v->data = p;
    // realloc 如果开不出来，原来的空间就释放了free
    // realloc失败，返回空,判断防止丢失
    //v->data = (int *)realloc(v->data, sizeof(int) * v->size);
    return 1;
}

int insert(Vector *v, int ind, int val) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    if (v->size == v->length) {
        if (!expand(v)) return 0;
        printf("expand Vector success = (%d)\n", v->size);
    }
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length++;
    return 1;;
}

int erase(Vector *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length--;
    return 1;
}

void output(Vector *v) {
    printf("Vector(%d) = [", v->length);
    for (int i = 0; i < v->length; i++) {
        i && printf(", ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    Vector *v = init(1);
    #define max_op 20
    int op, ind, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        ind = rand() % (v->length + 3) - 1; // 避开0
        val = rand() % 100;
        switch (op) {
            case 2:
            case 3:
            case 0: {
                printf("insert %d at %d to Vector = %d\n",
                       val, ind, insert(v, ind, val));   
                output(v);
                cout << endl;
            } break;
            case 1: {
                printf("erase element at %d from Vector = %d\n",
                      ind, erase(v, ind));
                output(v);
                cout << endl;
            } break;
        }
    }
    clear(v);
    return 0;
}
