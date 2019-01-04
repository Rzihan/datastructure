//
// Created by Pan梓涵 on 2019/1/1.
//

#ifndef DATASTRUCTURE_CIRLINKLIST_H
#define DATASTRUCTURE_CIRLINKLIST_H

#include "LinkList.h"

typedef LinkList CirLinkList;

/**
 * 初始化一个空的单循环链表
 * @param L
 * @return
 */
Status InitList_CL(CirLinkList &L);

/**
 * 循环链表的删除直接后继结点操作
 * @param L
 * @param p
 * @param e
 * @return
 */
Status DeleteAfter_CL(CirLinkList &L, LNode *p, ElemType &e);

#endif //DATASTRUCTURE_CIRLINKLIST_H
