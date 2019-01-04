//
// Created by Pan梓涵 on 2019/1/1.
//

#ifndef DATASTRUCTURE_DULINKLIST_H
#define DATASTRUCTURE_DULINKLIST_H

#include "../base/elem.h"
#include "../base/statu.h"

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

/**
 * 初始化双向链表L
 * @param L
 * @return
 */
Status InitList_DuL(DuLinkList &L);

/**
 * 销毁双向链表L
 * @param L
 * @return
 */
Status DestroyList_DuL(DuLinkList &L);

/**
 * 双向链表L置空
 * @param L
 * @return
 */
Status ClearList_DuL(DuLinkList L);

/**
 * 双向链表L判空
 * @param L
 * @return
 */
Status ListEmpty_DuL(DuLinkList L);

/**
 * 在p结点之前插入q结点
 * @param p
 * @param q
 * @return
 */
Status InsertBefore_DuL(DuLNode *p, DuLNode *q);

/**
 * 在p结点之后插入q结点
 * @param p
 * @param q
 * @return
 */
Status InsertAfter_DuL(DuLNode *p, DuLNode *q);

/**
 * 删除指针p所指向的结点，并用参数e返回p结点的元素值
 * @param p
 * @param e
 * @return
 */
Status Delete_DuL(DuLNode *p, ElemType &e);

#endif //DATASTRUCTURE_DULINKLIST_H
