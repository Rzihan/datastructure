//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_HEAP_H
#define DATASTRUCTURE_HEAP_H

#include "../sort/RcdSqList.h"
#include "../base/statu.h"

typedef struct {
    RcdType *rcd;   // 堆基址，0号单元闲置
    int n;          // 堆长度
    int size;       // 堆容量
    int tag;        // 标志：tag = 0为小顶堆，tag = 1为大顶堆
    int (*prior)(KeyType, KeyType);
    // 函数变量，用于关键字优先级比较
} Heap; // 堆类型
int greatPrior(int x, int y) { return x >= y; }  // 大顶堆优先函数
int lessPrior(int x, int y) { return x <= y; }   // 小顶堆优先函数

/**
 * 初建最大容量为size的空堆H，tag为小顶堆和大顶堆的标志
 * @param H
 * @param size
 * @param tag
 * @param prior 相应的优先函数
 * @return
 */
Status InitHeap(Heap &H, int size, int tag,
                int (*prior)(KeyType, KeyType));

/**
 * 用E建长度为n的堆H，容量为size， tag为小顶堆和大顶堆的标志
 * @param H
 * @param E
 * @param n
 * @param size
 * @param tag
 * @param prior 相应的优先函数
 */
void MakeHeap(Heap &H, RcdType *E, int n, int size, int tag,
              int (*prior)( KeyType, KeyType));

/**
 * 销毁堆H
 * @param H
 * @return
 */
Status DestroyHeap(Heap &H);

/**
 * 对位置为pos的结点做筛选
 * @param H
 * @param pos
 */
void shiftDown(Heap &H, int pos);

/**
 * 将e插入堆
 * @param H
 * @param e
 * @return
 */
Status InsertHeap(Heap &H, RcdType e);

/**
 * 删除堆顶结点，用e返回其值
 * @param H
 * @param e
 * @return
 */
Status RemoveFirstHeap(Heap &H, RcdType &e);

/**
 * 删除位置pos的结点，用e返回其值
 * @param H
 * @param pos
 * @param e
 * @return
 */
Status RemoveHeap(Heap &H, int pos, RcdType &e);

/**
 * 堆排序
 * @param L
 */
void HeapSort(RcdSqList &L);
#endif //DATASTRUCTURE_HEAP_H
