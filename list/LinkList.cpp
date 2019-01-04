//
// Created by Pan梓涵 on 2019/1/1.
//
#include <malloc.h>
#include "LinkList.h"

Status InitList_L(LinkList &L) { // 初始化一个只含头结点的空单链表L
    if (nullptr == (L = (LNode *) malloc(sizeof(struct LNode)))) // 生成新结点
        return OVERFLOW;
    L->next = nullptr;
    return OK;
}

LNode *Search_L(LinkList L, ElemType e) {
    LNode *p;
    if (nullptr == L->next) return nullptr; // L是空表
    p = L->next;
    while (p->data != e && p != nullptr) p = p->next; // 查找值为e的结点
    return p;  // 若p==NULL则返回NULL，否则p->data==e，查找成功
}

LNode *NextElem_L(LNode *p) {  // 返回指向p结点的后继结点指针
    if (nullptr == p->next) return nullptr;
    return p->next;
}

LNode *MakeNode_L(ElemType e) { // 构造数据域为e的单链表结点
    LNode *p;
    p = (LNode *) malloc(sizeof(LNode)); // 分配结点空间
    if (p != nullptr) {
        p->data = e;
        p->next = nullptr;
    }
    return p;
}

Status InsertAfter_L(LNode *p, LNode *q) {  // 在p结点之后插入q结点
    if (nullptr == p || nullptr == q) return ERROR;  // 参数不合理
    q->next = p->next;       // 修改q结点的指针域
    p->next = q;             // 修改p结点的指针域
    return OK;
}

Status DeleteAfter_L(LNode *p, ElemType &e) {
    LNode *q;
    if (nullptr == p || nullptr == p->next) return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

Status CreatList_L(LinkList &L, int n, ElemType *A) {
    // 建立一个长度为n的单链表，数组A[]提供n个元素值
    LNode *p, *q;
    int i;
    if (OVERFLOW == InitList_L(L)) return OVERFLOW;
    p = L;
    for (i = 0; i < n; i++) { // 依次在表尾插入n个结点
        q = MakeNode_L(A[i]);
        InsertAfter_L(p, q);
        p = q;                 // 令p指向新插入结点
    }
    return OK;
}

void InverseList(LinkList L) { // 对带头结点的单链表L实现逆置
    LNode *p, *q;
    if (nullptr == L->next || nullptr == L->next->next) return;
    p = L->next;             // 指针p始终指向待插入结点
    L->next = nullptr;       // (1)将头结点与第一个结点断开
    while (p != nullptr) {   // (2)将第一个到最后一个结点依次插入到头结点后面
        q = p->next;         // 指针q始终指向待插入结点的后继
        InsertAfter_L(L, p); // 将待插入结点插入到头结点后面
        p = q;               // 指针p指向下一个待插入结点
    }
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
    // 将升序单链表La和Lb归并为新的单链表Lc
    LinkList pa, pb, pc, temp;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;      // 用La的头结点作为Lc的头结点
    while (pa && pb) // 依次处理La和Lb的当前结点
        if (pa->data <= pb->data) {
            temp = pa->next;
            InsertAfter_L(pc, pa);
            pc = pa;
            pa = temp;
        } else {
            temp = pb->next;
            InsertAfter_L(pc, pb);
            pc = pb;
            pb = temp;
        }
    pc->next = pa ? pa : pb; // 插入剩余段
    free(Lb);    // 释放Lb的头结点
}
