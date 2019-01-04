//
// Created by Pan梓涵 on 2019/1/4.
//

#include <malloc.h>
#include "GList.h"

int GListDepth(GList L) {  // 求广义表L的深度
    if (nullptr == L) return 1;
    // 表头深度加1
    int h1 = GListDepth(L->un.ptr.hp) + 1;
    // 表尾的深度与原表相同
    int h2 = GListDepth(L->un.ptr.tp);
    return h1 >= h2 ? h1 : h2;
}

Status Append(GList &L, GLNode *p) {
    GList tail = (GList) malloc(sizeof(GLNode));
    if (nullptr == tail) return OVERFLOW;
    tail->tag = LIST;
    tail->un.ptr.hp = p;
    tail->un.ptr.tp = nullptr;
    if (nullptr == L) L = tail;
    else { // 定位至最后一个结点
        GLNode *pp = L;
        for (; pp->un.ptr.tp != nullptr; pp = pp->un.ptr.tp);
        pp->un.ptr.tp = tail;
    }
    return OK;
}
