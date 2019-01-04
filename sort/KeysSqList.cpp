//
// Created by Pan梓涵 on 2019/1/4.
//

#include <malloc.h>
#include "KeysSqList.h"
#include "../base/statu.h"

/**
 * 一趟基数排序
 * @param rcd
 * @param rcd1
 * @param n
 * @param i
 * @param count
 * @param pos
 * @param radix
 */
void RadixPass(KeysRcdType rcd[], KeysRcdType rcd1[], int n, int i,
               int count[], int pos[], int radix) {
    int k, j;
    for (k = 1; k <= n; k++) count[rcd[k].keys[i]]++; // 对各种取值计数
    pos[0] = 1;
    for (j = 1; j < radix; ++j) pos[j] = count[j - 1] + pos[j - 1]; // 求起始位置
    for (k = 1; k <= n; ++k) { // 收集
        j = rcd[k].keys[i];
        rcd1[pos[j]++] = rcd[k];   // 复制记录，对应的起始位置加1
    }
}

/**
 * 基数排序
 * @param L
 * @return
 */
Status RadixSort(KeysSqList &L) { // 对顺序表 L 进行计数基数排序
    KeysRcdType *rcd1; // 开设同等大小的辅助空间用于复制数据
    int i = 0, j, *count, *pos;
    count = (int *) malloc(L.radix * sizeof(int));
    pos = (int *) malloc(L.radix * sizeof(int));
    rcd1 = (KeysRcdType *) malloc((L.length + 1) * sizeof(KeysRcdType));
    if (nullptr == count || nullptr == pos || nullptr == rcd1) return OVERFLOW;
    while (i < L.digitNum) {
        for (j = 0; j < L.radix; ++j) count[j] = 0; // 初始化
        if (0 == i % 2)  // 对L.rcd进行一趟基数排序，结果存入rcd1
            RadixPass(L.rcd, rcd1, L.length, i++, count, pos, L.radix);
        else    // 对rcd1进行一趟基数排序，结果存入 L.rcd
            RadixPass(rcd1, L.rcd, L.length, i++, count, pos, L.radix);
    }
    if (1 == L.digitNum % 2) // 排序后的结果在rcd1中，复制至L.rcd 中
        for (j = 1; j <= L.length; ++j) L.rcd[j] = rcd1[j];
    free(count);
    free(pos);
    free(rcd1);
    return OK;
} 