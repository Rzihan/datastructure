//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_PTREE_H
#define DATASTRUCTURE_PTREE_H

typedef int TElemType;

typedef struct PTNode {
    TElemType data;   // 元素值
    int parent;       // 双亲位置，根结点的parent值为-1
} PTNode;             // 双亲结点类型

typedef struct {
    PTNode *nodes;    // 由初始化操作分配的结点数组
    int r, nodeNum;   // 根位置和结点数
} PTree;              // 树的双亲存储结构类型

#endif //DATASTRUCTURE_PTREE_H
