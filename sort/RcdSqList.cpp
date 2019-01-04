//
// Created by Pan梓涵 on 2019/1/4.
//

#include "RcdSqList.h"

void InsertionSort(RcdSqList &L) {
    int i, j;
    // 对顺序表 L 作直接插入排序。
    for (i = 2; i <= L.length; ++i)
        if (L.rcd[i].key < L.rcd[i - 1].key) {
            L.rcd[0] = L.rcd[i];          // 复制为监视哨
            for (j = i - 1; L.rcd[0].key < L.rcd[j].key; --j)
                L.rcd[j + 1] = L.rcd[j];       // 记录后移
            L.rcd[j + 1] = L.rcd[0];     // 插入到正确位置
        }
}

void ShellInsert(RcdSqList &L, int dk) { // 对顺序表L作一趟希尔排序，增量为dk
    int i, j;
    for (i = 1; i <= L.length - dk; ++i)
        if (L.rcd[i + dk].key < L.rcd[i].key) { // 需将L.rcd[i+dk]插入有序序列
            L.rcd[0] = L.rcd[i + dk];  // 暂存在L.rcd[0]
            j = i + dk;
            do {
                j -= dk;
                L.rcd[j + dk] = L.rcd[j]; // 记录后移
            } while (j - dk > 0 && L.rcd[0].key < L.rcd[j - dk].key); // 判断是否需要继续移动
            L.rcd[j] = L.rcd[0]; // 插入
        }
}

void ShellSort(RcdSqList &L, int d[], int t) {
    // 按增量序列d[0..t-1]对顺序表L作希尔排序
    int k;
    for (k = 0; k < t; ++k)
        ShellInsert(L, d[k]); //一趟增量为d[k]的插入排序
}
