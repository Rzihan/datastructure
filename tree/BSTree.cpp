//
// Created by Pan梓涵 on 2019/1/4.
//

#include <malloc.h>
#include "BSTree.h"

BSTree SearchBST(BSTree T, KeyType key) { // 二叉查找树递归查找
    if (nullptr == T) return nullptr; // 查找失败
    if (T->data.key == key) return T; // 查找成功
    if (T->data.key > key)
        return SearchBST(T->lchild, key); // 在左子树上继续查找
    return SearchBST(T->rchild, key); // 在右子树上继续查找
}

/**
 * 二叉查找树非递归查找
 * @param T
 * @param key
 * @return
 */
BSTree SearchBST0(BSTree T, KeyType key) {
    while (T != nullptr) {
        if (T->data.key == key) return T;  // 查找成功
        else if (T->data.key > key) T = T->lchild;  // 在左子树中继续查找
        else if (T->data.key < key) T = T->rchild;  // 在右子树中继续查找
    }
    return nullptr;                                // 查找失败
}

Status InsertBST(BSTree &T, RcdType e) { // 二叉查找树插入
    if (nullptr == T) {  // 创建新插入的结点并作为根结点
        BSTNode *s = (BSTNode *) malloc(sizeof(BSTNode));
        if (nullptr == s) return OVERFLOW;
        s->data = e;
        s->lchild = nullptr;
        s->rchild = nullptr;
        T = s;
        return TRUE;
    }
    if (e.key < T->data.key) return InsertBST(T->lchild, e);
    // 插入结点的值小于根结点值，在左子树递归插入
    if (e.key > T->data.key) return InsertBST(T->rchild, e);
    // 插入结点的值大于根结点值，在右子树递归插入
    return FALSE; // e.key==T->data.key，结点已存在
}

void DeleteNode(BSTree &p) {
    BSTNode *q, *s;
    q = p; //令q指向要删除的p结点
    if (nullptr == p->rchild) {  // 右子树空则只需重接它的左子树
        q = p;
        p = p->lchild;
        free(q);
    } else if (nullptr == p->lchild) { // 只需重接它的右子树
        p = p->rchild;
        free(q);
    } else {    // 左右子树均不空
        s = p->lchild;
        while (s->rchild != nullptr) {
            q = s;
            s = s->rchild;
        } //向右走到尽头，令s 指向被删结点的直接前驱
        p->data = s->data;  //将直接前驱s结点的值赋予被删结点
        if (q == p) q->lchild = s->lchild; //删除s结点只需将其左子树置为q结点的左子树
        else q->rchild = s->lchild; // 删除s结点只需将其左子树置为q结点的右子树
        free(s);
    }
}

Status DeleteBST(BSTree &T, KeyType key) {
    if (nullptr == T) return FALSE;  // 不存在值为key的结点
    if (key == T->data.key) {        // 找到值为key的结点
        DeleteNode(T);
        return TRUE;
    }
    if (key < T->data.key)
        return DeleteBST(T->lchild, key); // 返回在左子树上删除的结果
    return DeleteBST(T->rchild, key);     // 返回在右子树上删除的结果
}
