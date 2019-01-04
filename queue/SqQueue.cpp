//
// Created by Pan梓涵 on 2018/12/31.
//
#include "SqQueue.h"

Status DeQueue_Sq(SqQueue &Q, ElemType &e) {
    // 若队列不空，则删除队列Q中的头元素，用 e 返回其值
    if(Q.front==Q.rear)  return FALSE;
    e = Q.elem[Q.front];
    Q.front = (Q.front+1)%Q.maxSize; // Q.front循环加1
    return OK;
}

Status EnQueue_Sq(SqQueue &Q, ElemType e) {
    // 若当前队列不满，在队列的尾元素之后，插入元素 e 为新的队列尾元素
    if((Q.rear+1)%Q.maxSize==Q.front)  return ERROR;
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear+1)%Q.maxSize;
    return OK;
}
