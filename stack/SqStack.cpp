//
// Created by Pan梓涵 on 2018/12/31.
//
#include <malloc.h>
#include "SqStack.h"

Status InitStack_Sq(SqStack &S, int size, int inc)  {
    // 初始化空的顺序栈S
    S.elem = (ElemType*)malloc(size*sizeof(ElemType));
    if(nullptr ==S.elem) return OVERFLOW;
    S.top = 0;       // 置S为空栈
    S.size = size;
    S.increment = inc;
    return OK;
}

Status Push_Sq(SqStack &S, ElemType e)  {  // 元素e压入栈S
    ElemType *newbase;
    if(S.top>=S.size)  {  // 扩容
        newbase = (ElemType*)realloc(S.elem, (S.size+S.increment)*sizeof(ElemType));
        if(nullptr ==newbase) return OVERFLOW;
        S.elem = newbase;
        S.size += S.increment;
    }
    S.elem[S.top] = e;
    S.top++;
    return OK;
}
