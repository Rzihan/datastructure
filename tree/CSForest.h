//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_CSFOREST_H
#define DATASTRUCTURE_CSFOREST_H

#include "CSTree.h"

/**
 * 先序遍历森林
 * @param F
 * @param visit
 * @return
 */
Status PreOrderTraverseForest(CSForest F, Status(*visit)(TElemType));

/**
 * 求森林F的深度 
 * @param F
 * @return
 */
int ForestDepth(CSForest F);

/**
 * 查找
 * @param F
 * @param e
 * @return
 */
CSTreeNode* Search(CSForest F, TElemType e);

#endif //DATASTRUCTURE_CSFOREST_H
