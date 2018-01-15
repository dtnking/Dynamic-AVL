#ifndef _NODEHELPER_H
#define _NODEHELPER_H

void initNode(Node *node, Node *left, Node *right, int bf,uint32_t rv, uint32_t cv);
Node *createNode(Node *newNode,uint32_t val);
int findAddRelativeVal(Node **node,Node *nodeToAdd,int absoluteAddVal,int previousValue);
double printRelValFromSmallest(Node **rootPtr);

#endif // _AVL_H
