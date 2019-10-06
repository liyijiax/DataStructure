/*************************************************************************
	> File Name: 4.单向循环链表.cpp
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
using namespace std;

typedef struct List_Node {
    int data;
    struct List_Node *next;
}Node;

typedef struct List {
    Node head;
    int length;
}List;

Node *init_node(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = &l->head;
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
    p->next = n;
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
    srand(time(0));
    #define max_op 20
    int op, ind, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d to %d is %d\n", 
                       val, ind, insert(l, ind, val));
                output(l);
                printf("\n");
            } break;
            case 3: {
                printf("delete %d of list is %d\n",
                       ind, delete_node(l, ind));
                output(l);
                printf("\n");
            } break;
        }

    }
    clear_list(l);
    return 0;
}
