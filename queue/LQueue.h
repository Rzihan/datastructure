//
// Created by Pan梓涵 on 2019/1/1.
//

#ifndef DATASTRUCTURE_LQUEUE_H
#define DATASTRUCTURE_LQUEUE_H

#include "../base/statu.h"
#include "../tree/BiTree.h"

typedef BiTree ElemType;

typedef struct LQNode {
    ElemType  data;
    struct LQNode  *next;
} LQNode, *QueuePtr; // 结点和结点指针类型

typedef struct {
    QueuePtr  front;  // 队头指针
    QueuePtr  rear;   // 队尾指针
} LQueue; // 链队列

/**
 * 构造一个空队列
 * @param Q
 */
void InitQueue_LQ(LQueue &Q);

/**
 * 销毁队列Q
 * @param Q
 */
void DestroyQueue_LQ(LQueue &Q);

/**
 * 若队列 Q 为空，则返回TRUE，否则FALSE
 * @param Q
 * @return
 */
Status QueueEmpty_LQ(LQueue Q);

/**
 * 返回队列 Q 中元素个数，即队列的长度
 * @param Q
 * @return
 */
int QueueLength_LQ(LQueue Q);

/**
 * 若队列不空，则用 e 返回Q的队头元素，并返回OK；否则ERROR
 * @param Q
 * @param e
 * @return
 */
Status GetHead_LQ(LQueue Q, ElemType &e);

/**
 * 在队列Q的队尾插入元素 e
 * @param Q
 * @param e
 * @return
 */
Status EnQueue_LQ(LQueue &Q, ElemType  e);

/**
 * 若队列Q非空，则删除队头元素，用 e 返回其值，并返回OK；否则ERROR
 * @param Q
 * @param e
 * @return
 */
Status DeQueue_LQ(LQueue &Q, ElemType &e);

#endif //DATASTRUCTURE_LQUEUE_H
