/*************************************************************************
	> File Name: vector.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月04日 星期五 11时19分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct Vector {
    int length, size;
    int *data;
}Vector;

Vector *init(int n) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->size = n;
    v->length = 0;
    v->data = (int *)malloc(sizeof(int) * v->size);
    return v;
}

Vector *left_move(Vector *v, int k) {
    for (int i = 0; i < k; i++) {
        int tmp = v->data[0];
        for (int i = 0; i < v->length - 1; i++) {
            v->data[i] = v->data[i + 1];
        }
        v->data[v->length - 1] = tmp;
    }
    return v;
}

void clear(Vector *v) {
    free(v->data);
    free(v);
    return ;
}

int main() {
    int n ,k;
    scanf("%d %d", &n, &k);
    Vector *v = init(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v->data[i]);
        v->length++;
    }
    v = left_move(v, k);
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", v->data[i]);
    }
    return 0;
}
