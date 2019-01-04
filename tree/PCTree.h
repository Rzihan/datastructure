//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_PCTREE_H
#define DATASTRUCTURE_PCTREE_H

typedef int TElemType;

typedef struct ChildNode {
    int childIndex;                	// 孩子在结点数组的位置
    struct ChildNode *nextChild; 	// 下一个孩子
} ChildNode;                        // 孩子链表中的结点类型

typedef struct {
    TElemType data;                 // 元素值
    int parent;                    	// 双亲位置
    struct ChildNode *firstChild; 	// 孩子链表头指针
} PCTreeNode;                       //  双亲孩子结点类型

typedef struct {
    PCTreeNode *nodes;              // 结点数组
    int nodeNum, r;                 // 结点元素个数,根位置
} PCTree;                           // 树的双亲孩子存储结构类型

#endif //DATASTRUCTURE_PCTREE_H
