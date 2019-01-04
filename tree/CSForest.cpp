//
// Created by Pan梓涵 on 2019/1/4.
//

#include "CSForest.h"

Status PreOrderTraverseForest(CSForest F, Status(*visit)(TElemType)) {
    if (nullptr == F) return OK;                         // 森林为空
    if (ERROR == visit(F->data)) return ERROR;           // 访问第一棵树的根结点
    if (ERROR == PreOrderTraverseForest(F->firstChild, visit))
        return ERROR;                                    // 递归先序遍历第一棵树的子树森林
    return PreOrderTraverseForest(F->nextSibling, visit);// 递归先序遍历剩余森林
}

int ForestDepth(CSForest F) {
    int dep1, dep2, dep;
    if (nullptr == F) dep = 0;                  // 森林为空，深度则为0
    else {
        dep1 = ForestDepth(F->firstChild);      // 求第一棵树的子树森林的深度
        dep2 = ForestDepth(F->nextSibling);     // 求剩余森林的深度
        dep = dep1 + 1 > dep2 ? dep1 + 1 : dep2;// 森林的深度
    }
    return dep;
}

CSTreeNode* Search(CSForest F, TElemType e) {
    CSTNode *result = nullptr;
    if (nullptr == F) return nullptr;  // 森林为空，返回NULL
    if (F->data == e) return F;        // 找到结点，返回其指针
    if ((result = Search(F->firstChild, e)) != nullptr)
        return result;                 // 在第一棵树的子树森林查找
    return Search(F->nextSibling, e);  // 在剩余森林中查找
}
