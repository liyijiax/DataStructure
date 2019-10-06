/*************************************************************************
	> File Name: 4.那位同学最优秀.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月04日 星期五 18时32分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct Vector {
    int len, size;
    int *data;
}Vector;

Vector *init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->size = n;
    p->len = 0;
    p->data = (int *)malloc(sizeof(int) * p->size);
    return p;
}

Vector *delete_vector(Vector *v, int num) {
    if (num >= v->len) return v;
    for (int i = num + 1; i < v->len; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->len--;
    return v;
}

void output(Vector *v) {
    for (int i = 0; i < v->len; i++) {
        i && cout << " ";
        cout << v->data[i];
    }
    cout << endl;
}

void clear(Vector *v) {
    free(v->data);
    free(v);
    return ;
}

int main() {
    int n, m, num;
    cin >> n >> m;
    Vector *v = init(n);
    for (int i = 0; i < n; i++) {
        v->data[i] = i + 1;
        v->len++;
    }
    for (int i = 0; i < m; i++) {
        cin >> num;
        v = delete_vector(v, num - 1);
    }
    int order;
    order = v->len / 2;
    cout << v->data[order] << endl;
    //output(v); // 不输出真的找不到这个bug
    clear(v);
    return 0;
}
