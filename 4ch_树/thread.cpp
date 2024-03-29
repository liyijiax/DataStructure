/*************************************************************************
	> File Name: thread.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月19日 星期六 14时40分48秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define NORMAL 0
#define THREAD 1 


typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

void output(Node *node);

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = NULL;
    p->ltag = p->rtag = NORMAL;
    return p;
}

Node *insert(Node *node, int val) {
    if (node == NULL) return getNewNode(val);
    if (node->key == val) return NULL;
    if (node->key > val) node->lchild = insert(node->lchild, val);
    else node->rchild = insert(node->rchild, val);
    return node;
}

void build_thread(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
    return ;
}

void in_order(Node *node) {
    if (node == NULL) return ;
    if(node->ltag == NORMAL) in_order(node->lchild);
    printf("%d ", node->key);
    if(node->rtag == NORMAL) in_order(node->rchild);
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    if (node->ltag == NORMAL) clear(node->lchild);
    if (node->rtag == NORMAL) clear(node->rchild);
    free(node);
    return ;
}

Node *most_left(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void output(Node *node) {
    if (node == NULL) return ;
    Node *p = most_left(node);
    while (p) {
        printf("%d ", p->key);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    clock_t a = clock();
    in_order(root), printf("\n");
    clock_t b = clock();
    output(root), printf("\n");
    clock_t c = clock();
    cout << b - a << endl;
    cout << c - b << endl;
    clear(root);
    return 0;
}
