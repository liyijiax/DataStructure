/*************************************************************************
	> File Name: 1.binary_serzrch_tree.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月28日 星期四 19时03分15秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else  root->rchild = insert(root->rchild, key);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->lchild = erase(root->lchild,key);
    else (key > root->key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(rooot);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

void in_order_output(Node *root) {
    if (root == NULL) return ;
    in_order_output(root->lchild);
    printf("%d ", root->key);
    in_order_output(root->rchild);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(rooot);
    return ;
}

int main() {
    int op, val;
    Node *root = NULl;
    while (~scanf("%d%d",&op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        in_order_output(root), printf("\n");
    }
    clear(root);
    return 0;
}
