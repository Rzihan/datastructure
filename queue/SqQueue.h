//
// Created by Pan梓涵 on 2018/12/31.
//

#ifndef DATASTRUCTURE_SQQUEUE_H
#define DATASTRUCTURE_SQQUEUE_H

#include "../base/elem.h"
#include "../base/statu.h"

typedef struct {
    ElemType  *elem ;   // 存储空间的基址
    int front;          // 队头位标
    int rear;           // 队尾位标，指示队尾元素的下一位置
    int maxSize;        // 存储容量
} SqQueue;

/**
 * 初始化队列
 * @param Q
 * @param size
 * @return
 */
Status InitQueue_Sq(SqQueue &Q, int size);

/**
 * 销毁队列
 * @param Q
 * @return
 */
Status DestroyQueue_Sq(SqQueue &Q);

/**
 * 清空队列
 * @param Q
 */
void ClearQueue_Sq(SqQueue &Q);

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
Status QueueEmpty_Sq(SqQueue Q);

/**
 * 计算队列的长度
 * @param Q
 * @return
 */
int QueueLength_Sq(SqQueue Q);

/**
 * 获取对头元素
 * @param Q
 * @param e
 * @return
 */
Status GetHead_Sq(SqQueue Q, ElemType &e);

/**
 * 入队
 * @param Q
 * @param e
 * @return
 */
Status EnQueue_Sq(SqQueue &Q, ElemType e);

/**
 * 出队
 * @param Q
 * @param e
 * @return
 */
Status DeQueue_Sq(SqQueue &Q, ElemType &e);


#endif //DATASTRUCTURE_SQQUEUE_H
