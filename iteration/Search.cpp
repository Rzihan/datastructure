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
int BinSearch_ite(RcdType rcd[], KeyType key, int low, int high) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (rcd[mid].key == key)      // 中间关键字与key匹配，返回其下标
            return mid;
        else if (rcd[mid].key > key)  // 在低半区继续折半查找
            high = mid - 1;
        else low = mid + 1;           // 在高半区继续折半查找
    }
    return -1;                        // 找不到key，返回-1
}
