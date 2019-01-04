//
// Created by Pan梓涵 on 2018/12/31.
//

#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H

#include "../base/elem.h"
#include "../base/statu.h"

typedef struct {
    ElemType *elem; 	    // 存储空间的基址
    int top;	            // 栈顶元素的下一个位置，简称栈顶位标
    int size;	            // 当前分配的存储容量
    int increment;	        // 扩容时，增加的存储容量
}SqStack;     	            // 顺序栈

/**
 * 初始化顺序栈S
 * @param S
 * @param size
 * @param inc
 * @return
 */
Status InitStack_Sq(SqStack &S, int size, int inc);

/**
 * 销毁顺序栈S
 * @param S
 * @return
 */
Status DestroyStack_Sq(SqStack &S);

/**
 * 判断栈S是否空，若空则返回TRUE，否则FALSE
 * @param S
 * @return
 */
Status StackEmpty_Sq(SqStack S);

/**
 * 清空栈S
 * @param S
 */
void ClearStack_Sq(SqStack &S);

/**
 *  元素e压入栈S
 * @param S
 * @param e
 * @return
 */
Status Push_Sq(SqStack &S, ElemType e);

/**
 * 栈S的栈顶元素出栈，并用e返回
 * @param S
 * @param e
 * @return
 */
Status Pop_Sq(SqStack &S, ElemType &e);

/**
 * 取栈S的栈顶元素，并用e返回
 * @param S
 * @param e
 * @return
 */
Status GetTop_Sq(SqStack S, ElemType &e);

#endif //DATASTRUCTURE_SQSTACK_H
