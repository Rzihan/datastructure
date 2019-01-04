//
// Created by Pan梓涵 on 2019/1/4.
//
#include "Heap.h"

/**
 * 交换堆H中的第i个结点和第j个结点
 * @param H
 * @param i
 * @param j
 * @return
 */
Status swapHeapElem(Heap &H, int i, int j) {
    RcdType temp;
    if (i <= 0 || i > H.n || j <= 0 || j > H.n) return ERROR;
    temp = H.rcd[i];
    H.rcd[i] = H.rcd[j];
    H.rcd[j] = temp;
    return OK;
}

void shiftDown(Heap &H, int pos) { //对堆H中位置为pos的结点做筛选
    int c, rc;
    while (pos <= H.n / 2) {  // 若pos结点为叶子结点，循环结束
        c = pos * 2;          // pos结点的左孩子位置
        rc = pos * 2 + 1;     // pos结点的右孩子位置
        if (rc <= H.n && H.prior(H.rcd[rc].key, H.rcd[c].key)) c = rc; //取两者大值
        if (H.prior(H.rcd[pos].key, H.rcd[c].key)) return; // 若pos结点较优先则筛选结束
        swapHeapElem(H, pos, c); // 否则和较优先者c交换位置
        pos = c; // 继续向下调整
    }
}

Status InsertHeap(Heap &H, RcdType e) {
    int curr;
    if (H.n >= H.size - 1) return ERROR; // 堆已满，插入失败
    curr = ++H.n;
    H.rcd[curr] = e;                     // 将插入记录e加到堆尾
    while (1 != curr && H.prior(H.rcd[curr].key, H.rcd[curr / 2].key)) {
        swapHeapElem(H, curr, curr / 2); // 向上调整
        curr /= 2;
    }
    return OK;
}

Status RemoveFirstHeap(Heap &H, RcdType &e) {
    if (H.n <= 0) return ERROR;
    e = H.rcd[1];            // 取出堆顶记录
    swapHeapElem(H, 1, H.n); // 交换堆顶与堆尾记录
    H.n--;                   // 堆长度减1
    if (H.n > 1) shiftDown(H, 1);  // 向下筛选
    return OK;
}

void MakeHeap(Heap &H, RcdType *E, int n, int size, int tag,
              int (*prior)(KeyType, KeyType)) {
    int i;
    H.rcd = E; // E[1..n]是堆的n个结点，0号单元空闲
    H.n = n;
    H.size = size;
    H.tag = tag;
    H.prior = prior;
    for (i = n / 2; i > 0; i--) shiftDown(H, i);
}

void HeapSort(RcdSqList &L) {
    Heap H;
    int i;
    RcdType e;
    MakeHeap(H, L.rcd, L.length, L.size, 1, greatPrior);
    // 待排序列建大顶堆
    for (i = H.n; i > 0; i--) RemoveFirstHeap(H, e);
    // 堆顶与堆尾结点交换，堆长度减1，筛选新的堆顶结点
}
