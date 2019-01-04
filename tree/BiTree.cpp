//
// Created by Pan梓涵 on 2019/1/4.
//
#include <malloc.h>
#include "BiTree.h"
#include "../stack/LStack.h"
#include "../queue/LQueue.h"

BiTree MakeBiTree(TElemType e, BiTree L, BiTree R) {
    BiTree t;
    t = (BiTree) malloc(sizeof(BiTNode));
    if (nullptr == t) return nullptr;
    t->data = e;      // 根结点的值为e
    t->lchild = L;    // L作为t的左子树
    t->rchild = R;    // R作为t的右子树
    return t;
}

Status ReplaceLeft(BiTree &T, BiTree &LT) {
    BiTree temp;
    if (nullptr == T) return ERROR; // 树空
    temp = T->lchild;
    T->lchild = LT;  // LT作为T的左子树
    LT = temp;       // LT返回T的先前左子树
    return OK;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
    if (nullptr == T) return OK;
    if (ERROR == InOrderTraverse(T->lchild, visit)) return ERROR;    // 递归遍历T的左子树
    if (ERROR == visit(T->data)) return ERROR;                       // 访问结点的数据域
    return InOrderTraverse(T->rchild, visit);                        // 递归遍历T的右子树
}

/**
 * 栈S的元素类型是BiTree，从T结点出发，沿左分支走到
 * 走到底，沿途结点的指针入栈S，返回左下结点的指针
 * @param T
 * @param S
 * @return
 */
BiTNode *GoFarLeft(BiTree T, LStack &S) {
    if (nullptr == T) return nullptr;
    while (T->lchild != nullptr) {
        Push_LS(S, T);
        T = T->lchild;
    }
    return T;
}

void InorderTraverse_I(BiTree T, Status(*visit)(TElemType e)) {
    LStack S;
    InitStack_LS(S);
    BiTree p;
    p = GoFarLeft(T, S);                        // 找到最左下的结点
    while (p != nullptr) {
        visit(p->data);                         // 访问结点
        if (p->rchild != nullptr)               // 令p指向其右孩子为根的子树的最左下结点
            p = GoFarLeft(p->rchild, S);
        else if (StackEmpty_LS(S) != TRUE) Pop_LS(S, p); // 栈不空时退栈
        else p = nullptr; // 栈空表明遍历结束
    }
}

void LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
    if (T != nullptr) {
        LQueue Q;
        InitQueue_LQ(Q);
        BiTree p = T; //初始化
        visit(p->data);
        EnQueue_LQ(Q, p);
        while (OK == DeQueue_LQ(Q, p)) {
            if (p->lchild != nullptr) { //处理左孩子
                visit(p->lchild->data);
                EnQueue_LQ(Q, p->lchild);
            }
            if (p->rchild != nullptr) { //处理右孩子
                visit(p->rchild->data);
                EnQueue_LQ(Q, p->rchild);
            }
        }
    }
}

void DestroyBiTree(BiTree &T) {
    if (T != nullptr) {                //二叉树非空
        DestroyBiTree(T->lchild);      //递归销毁左子树
        DestroyBiTree(T->rchild);      //递归销毁右子树
        free(T);                       //释放根结点
    }
}

int BiTreeDepth(BiTree T) {
    int depthLeft, depthRight;
    if (nullptr == T) return 0;               // 空二叉树深度为0
    else {
        depthLeft = BiTreeDepth(T->lchild);   // 求左子树深度
        depthRight = BiTreeDepth(T->rchild);  // 求右子树深度
        return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
        // 左右子树深度的较大值+1
    }
}


void CountLeaf(BiTree T, int &count) { // 用count对二叉树T的叶子计数
    if (T != nullptr) { // 二叉树非空
        if (nullptr == T->lchild && nullptr == T->rchild) count++;  // 对叶子结点计数
        CountLeaf(T->lchild, count);  // 对左子树进行递归计数
        CountLeaf(T->rchild, count);  // 对右子树进行递归计数
    }
}

BiTree CreateBiTree(char *defBT, int &i) {
    BiTree T;
    TElemType ch;
    ch = defBT[i++];
    if('#' == ch) InitBiTree(T); // 空树
    else {
        T = MakeBiTree(ch, nullptr, nullptr);// 构造结点ch
        T->lchild = CreateBiTree(defBT, i);  // 构造左子树
        T->rchild = CreateBiTree(defBT, i);  // 构造右子树
    }
    return T;
}
