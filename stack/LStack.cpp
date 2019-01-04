//
// Created by Pan梓涵 on 2019/1/1.
//
#include <malloc.h>
#include "LStack.h"

Status Push_LS(LStack &S, ElemType e) {
    LSNode *t;
    t = (LSNode*)malloc(sizeof(LSNode));
    if (nullptr == t) return OVERFLOW;
    t->data = e;
    t->next = S;
    S = t;
    return OK;
}

Status Pop_LS(LStack &S, ElemType &e) {
    LSNode *t;
    if (nullptr == S) return ERROR;
    t = S;
    e = S->data;
    S = S->next;
    free(t);
    return OK;
}