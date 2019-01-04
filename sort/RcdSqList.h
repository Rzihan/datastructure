//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_RCDSQLIST_H
#define DATASTRUCTURE_RCDSQLIST_H

typedef  int  KeyType;  // 关键字类型为整数类型
typedef  struct {
    KeyType  key;           // 关键字项
                            // 其它数据项
} RecordType, RcdType;      // 记录类型

typedef struct {
    RcdType *rcd;     // 存储空间基址
    int length;       // 当前长度
    int size;         // 存储容量
} RcdSqList;  // 记录的顺序表

void InsertionSort ( RcdSqList &L );
#endif //DATASTRUCTURE_RCDSQLIST_H
