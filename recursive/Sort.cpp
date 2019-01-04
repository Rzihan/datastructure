//
// Created by Pan梓涵 on 2019/1/4.
//

#include <malloc.h>
#include "../sort/RcdSqList.h"

/**
 * 将相邻的有序区间SR[i...m]和SR[m+1...n]归并为有序的[i...n]
 * @param SR
 * @param TR
 * @param i
 * @param m
 * @param n
 */
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n) {
    int k, j;
    for (j = m + 1, k = i; i <= m && j <= n; k++) {
        //将SR中记录按关键字从小到大复制到TR中
        if (SR[i].key <= SR[j].key) TR[k] = SR[i++];
        else TR[k] = SR[j++];
    }
    while (i <= m) TR[k++] = SR[i++];
    while (j <= n) TR[k++] = SR[j++];
}

/**
 * 对R1[s..t]归并排序，若i为奇数，则排序后的记录存入R2[s..t]，否则R1[s..t]
 * @param R1
 * @param R2
 * @param i 
 * @param s
 * @param t
 */
void MSort(RcdType R1[], RcdType R2[], int i, int s, int t) {
    int m;
    if (s == t) {
        if (1 == i % 2) R2[s] = R1[s];
    } else {
        m = (s + t) / 2;
        MSort(R1, R2, i + 1, s, m);         // 对区间[s..m]递归归并排序
        MSort(R1, R2, i + 1, m + 1, t);     // 对区间[m+1..t]递归归并排序
        if (1 == i % 2)   // i为奇数
            Merge(R1, R2, s, m, t);         // 将R1[s..m]和R1[m+1..t]归并到R2[s..t]
        else              // i为偶数
            Merge(R2, R1, s, m, t);         // 将R2[s..m]和R2[m+1..t]归并到R1[s..t]
    }
}

/**
 * 对顺序表L作2-路归并排序
 * @param L
 */
void MergeSort(RcdSqList &L) {
    RcdType *R; // 辅助空间
    R = (RcdType *) malloc((L.length + 1) * sizeof(RcdType));
    MSort(L.rcd, R, 0, 1, L.length);  // 对L.rcd[1.. L.length]归并排序
    free(R);
}

/**
 * 对rcd[low..high] 作一次划分，并返回枢轴记录应该所处的位置
 * @param rcd
 * @param low
 * @param high
 * @return 
 */
int Partition(RcdType rcd[], int low, int high) {
    rcd[0] = rcd[low];          // 将枢轴移至数组的闲置分量
    while (low < high) {        // low和high从两端交替地向中间移动
        while (low < high && rcd[high].key >= rcd[0].key) --high;
        rcd[low] = rcd[high];    // 将比枢轴小的记录移到前端
        while (low < high && rcd[low].key <= rcd[0].key) ++low;
        rcd[high] = rcd[low];    // 将比枢轴大的记录移到后端
    }
    rcd[low] = rcd[0];
    return low;
}

/**
 * 对记录序列 rcd[s..t] 进行快速排序
 * @param rcd
 * @param s
 * @param t
 */
void QSort(RcdType rcd[], int s, int t) {
    if (s < t) { // 长度大于1
        // 对rcd[s..t]一趟划分，并返回枢轴位置
        int pivotloc = Partition(rcd, s, t);
        QSort(rcd, s, pivotloc - 1);    // 对前子序列递归进行排序
        QSort(rcd, pivotloc + 1, t);   // 对后子序列递归进行排序
    }
}

/**
 * 对记录的顺序表 L 进行快速排序
 * @param L
 */
void QuickSort(RcdSqList &L) {
    QSort(L.rcd, 1, L.length);
} 
