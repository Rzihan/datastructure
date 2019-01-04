//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_GLIST_H
#define DATASTRUCTURE_GLIST_H

#include "../base/statu.h"

typedef char AtomType;

typedef enum {
    ATOM, LIST
} ElemTag;//ATOM=0：原子；LIST=1：子表

typedef struct GLNode {
    ElemTag tag; //标志域，用于区分原子结点和表结点
    union {     //元素结点和表结点的联合部分
        AtomType atom; //atom是原子结点的值域
        struct {
            struct GLNode *hp, *tp;
        } ptr;
        //ptr是表结点的指针域，
        // ptr.hp和ptr.tp分别指向表头和表尾
    } un;
} *GList; //广义表类型

/**
 * 深度
 * @param L
 * @return
 */
int GListDepth(GList L);

/**
 * 在广义表L的末尾添加p元素
 * @param L
 * @param p
 * @return
 */
Status Append(GList &L, GLNode *p);
#endif //DATASTRUCTURE_GLIST_H
