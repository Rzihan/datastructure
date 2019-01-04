//
// Created by Pan梓涵 on 2019/1/4.
//

#include "TriTree.h"

Status PreOrderTraverse(TriTree T, Status (*visit)(TElemType e)) {
    TriTree p, pr;
    if (T != nullptr) {
        p = T;
        while (p != nullptr) {
            visit(p->data);                         // 输出当前的结点
            if (p->lchild) p = p->lchild;           // 若有左孩子，继续访问
            else if (p->rchild) p = p->rchild;      // 若有右孩子，继续访问
            else {                                  // 沿双亲指针链查找,找到第一个有右孩子的p结点，找不到则结束
                do {
                    pr = p;
                    p = p->parent;
                } while (p != nullptr && (p->rchild == pr || nullptr == p->rchild));
                if (p != nullptr) p = p->rchild;    // 找到后，p指向右孩子结点
            }
        }
    }
    return OK;
}
