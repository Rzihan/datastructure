//
// Created by Pan梓涵 on 2019/1/1.
//
#include <malloc.h>
#include "LQueue.h"

Status EnQueue_LQ(LQueue &Q, ElemType e){
    LQNode *p;
    p = (LQNode*)malloc(sizeof(LQNode)); // 申请新结点
    if(nullptr ==p) return OVERFLOW;
    p->data = e;
    p->next = nullptr;
    if(nullptr ==Q.front) Q.front = p; // e插入空队列
    else Q.rear->next = p;             // e插入非空队列
    Q.rear = p;                        // 队尾指针指向新的队尾
    return OK;
}

Status DeQueue_LQ (LQueue &Q, ElemType &e) {
    // 若队列Q非空，则删除队头元素，用 e 返回其值，并返回OK；否则返回ERROR
    LQNode *p;
    if(nullptr ==Q.front) return ERROR;
    p = Q.front;  // 指向队头结点
    e = p->data;  // 保存队头结点的数据
    Q.front = p->next;
    if(Q.rear==p) Q.rear = nullptr;    // 队列只有一个结点，删去后队列变空
    free(p);                           // 释放被删队头结点
    return OK;
}

