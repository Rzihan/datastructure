//
// Created by Pan梓涵 on 2018/12/31.
//
#include "SqList.h"

Status DeleteLast_Sq(SqList &L, ElemType &e)  {
    // 删除顺序表L的表尾元素，并用参数e返回其值
    if(0==L.length) return ERROR;  //空表
    e = L.elem[L.length-1];   // 被删除元素的值赋给e
    --L.length;  // 表长减1
    return OK;
}

int Search_Sq(SqList L, ElemType  e) {
    // 顺序表L中顺序查找数据元素e
    int i = 0;
    while(i<L.length && L.elem[i]!=e)  i++;  // 顺序查找e
    if(i<L.length) return i;   // 返回e的位序
    else return -1;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
    int i=0, j=0;
    int size, increment=10;
    ElemType ai, bj;
    size = La.length + Lb.length;
    InitList_Sq(Lc, size, increment); // 创建空表Lc
    while(i < La.length && j < Lb.length) { // 表La和Lb均非空
        GetElem_Sq(La, i, ai);
        GetElem_Sq(Lb, j, bj);
        if(ai<=bj) {
            Append_Sq(Lc,ai);
            ++i;
        } else {
            Append_Sq(Lc,bj);
            ++j;
        }
    }
    while(i< La.length) { // 表Lb空
        GetElem_Sq(La,i++,ai);
        Append_Sq(Lc,ai);
    }
    while(j< Lb.length) { // 表La空
        GetElem_Sq(Lb,j++,bj);
        Append_Sq(Lc,bj);
    }
}

