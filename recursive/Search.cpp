//
// Created by Pan梓涵 on 2019/1/4.
//

#include "../sort/RcdSqList.h"

/**
 * 在有序序列rcd[low..high]中折半查找目标关键字key
 * @param rcd
 * @param key
 * @param low
 * @param high
 * @return
 */
int BinarySearch(RcdType rcd[], KeyType key, int low, int high) {
    int mid = (low + high) / 2;
    if (high < low) return -1;
    if (rcd[mid].key == key)
        return mid;               //查找成功，返回中间关键字的下标
    else if (rcd[mid].key > key)  // 在前半区折半查找
        return BinarySearch(rcd, key, low, mid - 1);
    else                          // 在后半区折半查找
        return BinarySearch(rcd, key, mid + 1, high);
}
