//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_KEYSSQLIST_H
#define DATASTRUCTURE_KEYSSQLIST_H
typedef int KeysType;

typedef struct {
    KeysType *keys;     // 关键字
                        // 其它数据项
} KeysRcdType;          // 基数排序中的记录类型

typedef struct {
    KeysRcdType *rcd;       // 0号位置做哨兵
    int length;             // 顺序表长度
    int size;               // 顺序表容量
    int digitNum;           // 关键字位数
    int radix;              // 关键字基数
} KeysSqList; // 顺序表类型

#endif //DATASTRUCTURE_KEYSSQLIST_H
