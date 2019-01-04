//
// Created by Pan梓涵 on 2019/1/1.
//

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H

#include "../base/elem.h"
#include "../base/statu.h"

typedef struct LNode {
    ElemType data; 	     // 数据域
    struct LNode *next;  // 指针域，指向下一个结点
} LNode, *LinkList;
LinkList  L;             // L 为单链表的头指针

/**
 * 构造一个空的单链表Ｌ
 * @param L
 * @return
 */
Status InitList_L(LinkList &L);

/**
 * 查找结点操作，返回单链表L中第一个数据域值为e的结点地址，若不存在则返回NULL
 * @param L
 * @param e
 * @return
 */
LNode* Search_L(LinkList L, ElemType e);

/**
 * 返回p结点的直接后继结点的指针，若p结点是尾元结点则返回NULL
 * @param p
 * @return
 */
LNode* NextElem_L(LNode *p);

/**
 * 构造元素e的结点，返回指向该结点的指针
 * @param e
 * @return
 */
LNode* MakeNode_L(ElemType e);

/**
 * 在p结点之后插入q结点
 * @param p
 * @param q
 * @return
 */
Status InsertAfter_L(LNode *p, LNode *q);

/**
 * 删除p结点的直接后继结点，用e返回结点值，若L为空表或p为尾元结点则操作失败
 * @param L
 * @param p
 * @param e
 * @return
 */
Status DeleteAfter_L(LinkList &L, LNode *p, ElemType &e);

/**
 * 建立一个长度为n的单链表，数组A[]提供n个元素值
 * @param L
 * @param n
 * @param A
 * @return
 */
Status CreatList_L(LinkList &L, int n, ElemType *A);

/**
 * 对带头结点的单链表L实现逆置
 * @param L
 */
void InverseList(LinkList L);

/**
 * 将升序单链表La和Lb归并为新的单链表Lc
 * @param La
 * @param Lb
 * @param Lc
 */
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);
#endif //DATASTRUCTURE_LINKLIST_H
