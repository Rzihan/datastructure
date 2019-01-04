//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_HASHTABLE_H
#define DATASTRUCTURE_HASHTABLE_H

#include "../sort/RcdSqList.h"
#include "../base/statu.h"

typedef struct Node {
    RcdType r;
    struct Node *next;
} Node;

typedef struct {
    Node **rcd;      //指针类型,大小动态分配　
    int size;        // 哈希表容量
    int count;       // 当前表中含有的记录个数
    int (*hash)(KeyType key, int hashSize);  // 函数指针变量，用于选取的哈希函数
} HashTable;

/**
 * 初始化哈希表
 * @param H
 * @param size
 * @param hash
 * @return
 */
Status InitHash(HashTable &H, int size, int (*hash)(KeyType,int));

/**
 * 销毁哈希表
 * @param H
 * @return
 */
Status DestroyHash(HashTable &H);

/**
 * 查找
 * @param H
 * @param key
 * @return
 */
Node* SearchHash(HashTable H, KeyType key);

/**
 * 插入
 * @param H
 * @param e
 * @return
 */
Status InsertHash(HashTable &H, RcdType e);

/**
 * 删除
 * @param H
 * @param key
 * @param e
 * @return
 */
Status deleteHash(HashTable &H, KeyType key, RcdType &e);

#endif //DATASTRUCTURE_HASHTABLE_H
