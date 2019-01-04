//
// Created by Pan梓涵 on 2019/1/1.
//
#include <cstdlib>
#include "DuLinkList.h"

Status InsertBefore_DuL(DuLNode *p, DuLNode *q) { // 在p结点前插入q结点
    if (nullptr == p || nullptr == q || nullptr == p->prior)
        return ERROR;       // p指向头结点时不能在之前插入
    q->prior = p->prior;    // 修改对应的指针①
    q->next = p;            // 修改对应的指针②
    q->prior->next = q;     // 修改对应的指针③
    p->prior = q;           // 修改对应的指针④
    return OK;
}

Status Delete_DuL(DuLNode *p, ElemType &e) {
    if (nullptr == p || nullptr == p->prior) return ERROR; // 参数不合理
    if (p->next != nullptr) p->next->prior = p->prior; // 修改所对应的指针①
    p->prior->next = p->next;  // 修改所对应的指针②
    e = p->data;
    free(p);
    return OK;
}
