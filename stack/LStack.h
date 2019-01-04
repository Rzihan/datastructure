//
// Created by Pan梓涵 on 2019/1/1.
//

#ifndef DATASTRUCTURE_LSTACK_H
#define DATASTRUCTURE_LSTACK_H

#include "../base/statu.h"
#include "../tree/BiTree.h"

typedef BiTree ElemType;

typedef struct LSNode {
    ElemType data;	            // 数据域
    struct LSNode *next;	    // 指针域
} LSNode, *LStack;	            // 结点和链栈类型

/**
 *
 * 初始化链栈
 * @param S
 * @return
 */
Status InitStack_LS(LStack &S);

/**
 * 销毁链栈
 * @param S
 * @return
 */
Status DestroyStack_LS(LStack &S);

/**
 * 判断栈S是否为空栈，若空则返回TRUE，否则FALSE
 * @param S
 * @return
 */
Status StackEmpty_LS(LStack S);

/**
 * 元素压入栈
 * @param S
 * @param e
 * @return
 */
Status Push_LS(LStack &S, ElemType e);

/**
 * 栈顶元素出栈，并用e返回
 * @param S
 * @param e
 * @return
 */
Status Pop_LS(LStack &S, ElemType &e);

/**
 * 取栈S的栈顶元素，并用e返回
 * @param S
 * @param e
 * @return
 */
Status GetTop_LS(LStack S, ElemType &e);

#endif //DATASTRUCTURE_LSTACK_H
