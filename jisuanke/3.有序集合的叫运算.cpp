/*************************************************************************
	> File Name: 3.有序集合的叫运算.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月04日 星期五 11时41分58秒
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
    v->length = 0;
    v->size = n;
    v->data = (int *)malloc(sizeof(int) * v->size);
    return v;
}

Vector *merge_vector(Vector *a, Vector *b) {
    int size = max(a->length, b->length);
    Vector *v = init(size);
    int i = 0, j = 0;
    while (i < a->length && j < b->length) {
        if (a->data[i] == b->data[j]) {
            v->data[v->length++] = a->data[i];
            i++;
            j++;
        }
        while (a->data[i] < b->data[j] || 
               b->data[j] < a->data[i]) {
                   if (a->data[i] < b->data[j]) i++;
                   if (b->data[j] < a->data[i]) j++;
               }
    }
    return v;
}

void clear(Vector *v) {
    free(v->data);
    free(v);
    return ;
}

void output(Vector *v) {
    for (int i = 0; i < v->length; i++) {
        i && cout << " ";
        cout << v->data[i];
    }
    cout << endl;
    return ;
}
int main() {
    int n1, n2;
    cin >> n1;
    Vector *v1 = init(n1);
    for (int i = 0; i < n1; i++) {
        v1->length++;
        cin >> v1->data[i];
    }
    cin >> n2;
    Vector *v2 = init(n2);
    for (int i = 0; i < n2; i++) {
        v2->length++;
        cin >> v2->data[i];
    }
    Vector *v3 = merge_vector(v1, v2);
    cout << v3->length << endl;
    output(v3);
    clear(v1);
    clear(v2);
    clear(v3);
    return 0;
}
