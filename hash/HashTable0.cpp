//
// Created by Pan梓涵 on 2019/1/4.
//

#include <malloc.h>
#include "HashTable0.h"

Status InitHash(HashTable0 &H, int size, int (*hash)(KeyType, int),
                void (*collision)(int &, int)) {
    int i;
    H.rcd = (RcdType *) malloc(size * sizeof(RcdType));
    H.tag = (int *) malloc(size * sizeof(int));
    if (nullptr == H.rcd || nullptr == H.tag) return OVERFLOW;
    for (i = 0; i < size; i++) H.tag[i] = 0; // 置空标记
    H.size = size;
    H.count = 0;
    H.hash = hash;
    H.collision = collision;
    return OK;
}

Status SearchHash(HashTable0 H, KeyType key, int &p, int &c) {
    p = H.hash(key, H.size);// 求得哈希地址
    while ((1 == H.tag[p] && H.rcd[p].key != key) || -1 == H.tag[p]) {
        H.collision(p, H.size);
        c++;
    } // 求得下一探测地址p
    if (H.rcd[p].key == key && 1 == H.tag[p])
        return SUCCESS;
    else return UNSUCCESS;
}

int InsertHash(HashTable0 &H, RcdType e) { // 在哈希表H中插入记录e。
    int c = 0, j;
    if (SUCCESS == SearchHash(H, e.key, j, c)) return -1;
    else {
        H.rcd[j] = e;  //将记录e插入位置j
        H.tag[j] = 1;  //设置对应的标志位为1
        ++H.count;  //哈希表记录个数加1
        return c; //返回查找时发生冲突的次数
    }
}

Status deleteHash(HashTable0 &H, KeyType key, RcdType &e) {
    int j, c;
    if (UNSUCCESS == SearchHash(H, key, j, c))
        return UNSUCCESS;  // 表中没有与 key 相同关键字的记录
    else {
        e = H.rcd[j];  // 被删除的记录
        H.tag[j] = -1;  // 删除标记
        H.count--;  //哈希表记录个数减1
        return SUCCESS;
    }
}