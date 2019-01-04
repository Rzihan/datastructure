//
// Created by Pan梓涵 on 2019/1/1.
//
#include <malloc.h>
#include "CirLinkList .h"

Status InitList_CL(CirLinkList &L) { // // 初始化一个空的单循环链表L
    if (nullptr == (L = (LNode *) malloc(sizeof(struct LNode)))) // 生成新结点
        return OVERFLOW;
    L->next = L;
    return OK;
}

Status DeleteAfter_CL(CirLinkList &L, LNode *p, ElemType &e) {
    LNode *q;
    if (L == L->next) return ERROR; // 空表无法删除结点
    if (p->next == L) p = L; // 若p为尾元结点，令被删结点指向首元结点
    q = p->next;
    p->next = q->next; // 修改被删结点指针域
    e = q->data;
    free(q); // 释放被删结点
    return OK;
}

void Split(CirLinkList &LO, CirLinkList &LC, CirLinkList &LL) {
    // 将字母的单循环链表LO分拆成分别只含大写和小写字母的两个单循环链表LC和LL
    char ch;
    CirLinkList po, pc, pl;
    po = LO->next;
    LC = LO;            // 大写字母链表借用原链表头结点
    InitList_CL(LL);    // 初始化小写字母链表
    pc = LC;
    pl = LL;
    while (po != LO) {  // 分拆链表LO
        ch = static_cast<char>(po->data);
        if (ch >= 'A' && ch <= 'Z') {  // 大写字母链接到LC链表
            pc->next = po;
            pc = po;
        } else {  // 小写字母链接到LL链表
            pl->next = po;
            pl = po;
        }
        po = po->next;
    }
    pc->next = LC;
    pl->next = LL;
}
