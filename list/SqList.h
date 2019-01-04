//
// Created by Pan梓涵 on 2018/12/31.
//

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H

#include "../base/elem.h"
#include "../base/statu.h"

typedef struct {
    ElemType  *elem;    // 存储空间的基址
    int length;         // 当前长度
    int size;           // 存储容量
    int increment;      // 扩容的增量
} SqList; // 顺序表

/**
 * 初始化
 * @param L
 * @param size
 * @param inc
 * @return
 */
Status InitList_Sq(SqList &L, int size, int inc);

/**
 * 销毁
 * @param L
 * @return
 */
Status DestroyList_Sq(SqList &L);

/**
 * 清空
 * @param L
 * @return
 */
Status ClearList_Sq(SqList &L);

/**
 * 判空
 * @param L
 * @return
 */
Status ListEmpty_Sq(SqList L);

/**
 * 顺序表的长度
 * @param L
 * @return
 */
int ListLength_Sq(SqList L);

/**
 * 获取头元素
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem_Sq(SqList L, int i, ElemType &e);

/**
 * 搜索元素在表中的下标
 * @param L
 * @param e
 * @return
 */
int Search_Sq(SqList L, ElemType e);

/**
 * 遍历顺序表
 * @param L
 * @param visit
 * @return
 */
Status ListTraverse_Sq(SqList L, Status(*visit)(ElemType e));

/**
 * 添加元素到表中
 * @param L
 * @param i
 * @param e
 * @return
 */
Status PutElem_Sq(SqList &L, int i, ElemType e);

/**
 * 追加元素在表尾
 * @param L
 * @param e
 * @return
 */
Status Append_Sq(SqList &L, ElemType e);

/**
 * 删除最后一个元素
 * @param L
 * @param e
 * @return
 */
Status DeleteLast_Sq(SqList &L, ElemType &e);

#endif //DATASTRUCTURE_SQLIST_H
