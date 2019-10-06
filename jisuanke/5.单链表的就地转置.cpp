/*************************************************************************
	> File Name: 5.单链表的就地转置.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月04日 星期五 22时40分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct List {
    int length;
    Node head;
}List;

Node *init_node(char val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->length = 0;
    l->head.next = NULL;
    return l;
}

void insert(List *l, Node *node) {
    Node *p, *q;
    p = &l->head;
    node->next = p->next;
    p->next = node;
    l->length++;
}

void reverse(List *l) {
    Node *p, *q;
    p = l->head.next;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
}

int main() {
    int n;
    cin >> n;
    List *l = init_list();
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        Node *node = init_node(ch);
        insert(l, node);
    }
    //reverse(l);
    int flag = 0;
    Node *p = l->head.next;
    while (p) {
        flag && cout << " ";
        cout << p->data;
        flag = 1;
        p = p->next;
    }
    return 0;
}
