/*************************************************************************
	> File Name: 160.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月04日 星期五 16时24分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct ListNode *getlntersectionNode(
    struct ListNode *headA, struct ListNode *headB) {
   struct ListNode *p, *q;
    p = headA, q = headB;
        while (p != q) {
            if (p->val <= q->val && p != q) p = p->next;
            if (q->val <= p->val && p != q) q = q->next;
        }
        if (p == q) return p;
        else return NULL;
}
