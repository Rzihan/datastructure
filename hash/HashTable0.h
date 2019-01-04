//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_HASHTABLE0_H
#define DATASTRUCTURE_HASHTABLE0_H

#include "../sort/RcdSqList.h"
#include "../base/statu.h"

typedef struct {
    RcdType *rcd;    // 记录存储基址，动态分配数组
    int size;        // 哈希表容量
    int count;       // 当前表中含有的记录个数
    int *tag;        //标记， 0：空； 1：有效；-1：已删除
    int (*hash)(KeyType key, int hashSize); // 函数指针变量，选取的哈希函数
    void (*collision)(int &hashValue, int hashSize);// 函数指针变量，用于处理冲突的函数
} HashTable0;

/**
 * 初始化哈希表
 * @param H
 * @param size
 * @param hash
 * @param collision
 * @return
 */
Status InitHash(HashTable0 &H, int size, int (*hash)(KeyType, int), void (*collision)(int &, int));

/**
 * 销毁哈希表
 * @param H
 * @return
 */
Status DestroyHash(HashTable0 &H);

/**
 * 构造哈希表
 * @param H
 * @return
 */
Status CreateHash(HashTable0 &H);

/**
 * 查找
 * @param H
 * @param key
 * @param p
 * @param c
 * @return
 */
Status SearchHash(HashTable0 H, KeyType key, int &p, int &c);

/**
 * 插入
 * @param H
 * @param e
 * @return
 */
int InsertHash (HashTable0 &H, RcdType e);

/**
 * 删除
 * @param H
 * @param key
 * @param e
 * @return
 */
Status deleteHash(HashTable0 &H, KeyType key, RcdType &e);

#endif //DATASTRUCTURE_HASHTABLE0_H
