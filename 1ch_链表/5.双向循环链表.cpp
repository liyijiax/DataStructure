/*************************************************************************
	> File Name: 
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月05日 星期六 20时20分29秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define max_n 1000
using namespace std;

int a[max_n + 5] = {0};

typedef struct List_Node {
    int data;
    struct List_Node *next ,*prior;
}Node;

typedef struct List {
    Node head;
    int length;
}List;

Node *init_node(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    n->prior = NULL;
    return n;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = &l->head;
    l->head.prior = &l->head;
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val ) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    Node *n = init_node(val);
    Node *p, *q;
    p = &l->head;
    while (ind--) {
        p = p->next;
    }
    n->next = p->next;
    n->prior = p;
    p->next = n;
    n->next->prior = n;
    l->length++;
    return 1;
}

int delete_node(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    Node *p, *q;
    p = &l->head;
    while (ind--) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    p->next->prior = p;
    free(q);
    l->length--;
    return 1;
}
 
void output(List *l) {
    Node *p;
    p = l->head.next;
    int flag = 0;
    printf("List(%d) [", l->length);
    while (p != &l->head) {
        flag && cout << " ";
        printf("%d", p->data);
        p = p->next;
        flag = 1;
    }
    printf("]\n");
    return ;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    free(node);
}

void clear_list(List *list) {
    Node *p, *q;
    p = list->head.next;
    for (int i = 0; i < list->length; i++) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(list);
    return ;
}

int main() {
    List *l = init_list();
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(l, i, a[i]);
    }
    cin >> m;
    Node *p = l->head.next;
    while (p->data != m) {
        p = p->next;
    }
    Node *q = p;
    q = p->prior;
    cout << p->data;
    while (q != p) {
        if (q == &l->head) {
            q = q->prior;
            continue;
        }
        cout << " ";
        cout << q->data;
        q = q->prior;
    }
    clear_list(l);
    return 0;
}
