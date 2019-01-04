//
// Created by Pan梓涵 on 2019/1/4.
//

#include <malloc.h>
#include "HashTable.h"

Status InitHash(HashTable &H, int size, int (*hash)(KeyType, int)) {    //初始化哈希表
    int i;
    H.rcd = (Node **) malloc(size * sizeof(Node *));
    if (nullptr == H.rcd) return OVERFLOW;
    for (i = 0; i < size; i++) H.rcd[i] = nullptr;
    H.size = size;
    H.hash = hash;
    H.count = 0;
    return OK;
}

Node *SearchHash(HashTable H, KeyType key) {
    int p = H.hash(key, H.size);
    Node *np;
    for (np = H.rcd[p]; np != nullptr; np = np->next)
        if (np->r.key == key) return np;
    return nullptr;
}

Status InsertHash(HashTable &H, RcdType e) { // 在哈希表H中插入记录e
    int p;
    Node *np;
    if ((np = SearchHash(H, e.key)) == nullptr) { // 查找不成功时插入到表头
        p = H.hash(e.key, H.size);
        np = (Node *) malloc(sizeof(Node));
        if (nullptr == np)return OVERFLOW;
        np->r = e;
        np->next = H.rcd[p];
        H.rcd[p] = np;
        H.count++;
        return OK;
    } else return ERROR;
}
