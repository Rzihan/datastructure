//
// Created by Pan梓涵 on 2019/1/4.
//
#include <cstdarg>
#include <malloc.h>
#include "CSTree.h"

CSTree MakeTree(TElemType e, int n, ...) { // 创建根结点e和n棵子树的树
    int i;
    CSTree t, p, p1;
    va_list argptr;             // argptr是存放变长参数表信息的数组
    t = (CSTree) malloc(sizeof(CSTreeNode));
    if (nullptr == t) return nullptr;
    t->data = e;                // 根结点的值为e
    t->firstChild = t->nextSibling = nullptr;
    if (n <= 0) return t;       // 若无子树，则返回根结点
    va_start(argptr, n);        // 令argptr指向参数n后的第一个实参
    p = va_arg(argptr, CSTree); // 取第一棵子树的实参并转换未CSTree类型
    t->firstChild = p;
    p1 = p;
    for (i = 1; i < n; i++) {   // 将n棵树作为根结点的子树插入
        p = va_arg(argptr, CSTree);// 取下一棵子树的实参并转换未CSTree类型
        p1->nextSibling = p;
        p1 = p;
    }
    va_end(argptr);             // 取实参结束
    return t;
}

Status InsertChild(CSTree T, int i, CSTree c) {
    int j;
    CSTree p;
    if (nullptr == T || i < 1) return ERROR;
    if (1 == i) { // c插入为T的第1棵子树
        c->nextSibling = T->firstChild;
        T->firstChild = c; // c成为T的第1棵子树
    } else {
        p = T->firstChild;
        for (j = 2; p != nullptr && j < i; j++) p = p->nextSibling;  // 寻找插入位置
        if (j == i) { // 找到插入位置
            c->nextSibling = p->nextSibling;
            p->nextSibling = c;
        } else return ERROR;  // 参数i过大
    }
    return OK;
}
