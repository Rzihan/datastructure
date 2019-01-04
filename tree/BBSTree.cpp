//
// Created by Pan梓涵 on 2019/1/4.
//

#include <malloc.h>
#include "BBSTree.h"

/**
 * 对最小失衡子树p作右旋调整
 * @param p
 */
void R_Rotate(BBSTree &p) {
    BBSTree lc = p->lchild;// lc指向p结点的左孩子
    p->lchild = lc->rchild;// lc结点的右子树置为p结点的左子树
    lc->rchild = p;        // 置p结点（原根结点）为lc结点的右孩子
    p = lc;                // p指向新的根结点
}

/**
 * 对最小失衡子树p作左旋调整
 * @param p
 */
void L_Rotate(BBSTree &p) {
    BBSTree rc = p->rchild;// lc指向p结点的右孩子
    p->rchild = rc->lchild;// lc结点的左子树置为p结点的右子树
    rc->lchild = p;        // 置p结点（原根结点）为lc结点的左孩子
    p = rc;                // p指向新的根结点
}

#define LH +1   //左子树比右子树高，简称左高
#define EH 0    //左、右子树等高，简称等高
#define RH -1   //右子树比左子树高，简称右高

/**
 * 实现对树T的左平衡处理
 * @param T
 */
void LeftBalance(BBSTree &T) {
    BBSTree lc, rd;
    lc = T->lchild;      // lc指向T的左孩子
    switch (lc->bf) {    // 检查T的左子树的平衡因子,并作相应处理
        case LH:         // LL型，需右旋处理
            T->bf = lc->bf = EH;
            R_Rotate(T);
            break;
        case RH:         //新结点插入在T的左孩子的右子树上属于LR型做双旋处理
            rd = lc->rchild;
            switch (rd->bf) {    // 修改T及其左孩子的平衡因子
                case LH: T->bf = RH; lc->bf = EH; break;
                case EH: T->bf = lc->bf = EH; break;
                case RH: T->bf = EH; lc->bf = LH; break;
                default: break;
            }
            rd->bf = EH;
            L_Rotate(T->lchild); // 对T的左子树作左旋处理
            R_Rotate(T);         // 对T作右旋处理
            break;
        default:
            break;
    }
}

/**
 * 实现对树T的右平衡处理
 * @param T
 */
void RightBalance(BBSTree &T) {
    //todo 实现对树T的右平衡处理
}

Status InsertAVL(BBSTree &T, RcdType e, Status &taller) {
    if (nullptr == T) {   // T为空，树长高
        T = (BBSTree) malloc(sizeof(BBSTNode));
        T->data = e;
        T->bf = EH;
        T->lchild = nullptr;
        T->rchild = nullptr;
        taller = TRUE;
    } else if (e.key == T->data.key) { // 树中已存在和e相等的结点
        taller = FALSE;
        return FALSE; // 未插入
    } else if (e.key < T->data.key) { // 插入到左边
        if (FALSE == InsertAVL(T->lchild, e, taller)) return FALSE; //未插入
        if (TRUE == taller) {
            switch (T->bf) { // 检查T的平衡因子
                case LH: LeftBalance(T); taller = FALSE; break; // 原左高，左平衡处理（3）3）
                case EH: T->bf = LH; taller = TRUE; break;  // 原等高，左变高
                case RH: T->bf = EH; taller = FALSE; break; // 原右高，变等高
                default:break;
            }
        }
    } else {  // 插入到右子树
        if (FALSE == InsertAVL(T->rchild, e, taller)) return FALSE; //未插入
        if (TRUE == taller) {
            switch (T->bf) {
                case LH : T->bf = EH; taller = FALSE; break;
                case EH : T->bf = RH; taller = TRUE; break;
                case RH : RightBalance(T); taller = FALSE; break;
                default: break;
            }
        }
    }
    return TRUE;
}
