//
// Created by Pan梓涵 on 2019/1/4.
//
#include "SqBiTree.h"

Status is_Desendant(SqBiTree T, int u, int v) {
    if (u < 1 || u > T.lastIndex || v < 1 || v > T.lastIndex || v <= u)
        return FALSE;              // u和v的范围不合理
    while (v > u) {                // 根据性质5找v的祖先
        v = v / 2;
        if (v == u) return TRUE;   // v是u的子孙
    }
    return FALSE;                  // v不是u的子孙
}
