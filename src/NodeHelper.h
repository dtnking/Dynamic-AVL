#ifndef _NODEHELPER_H
#define _NODEHELPER_H

void initNode(Node *node, Node *left, Node *right, int bf,uint32_t rv, uint32_t cv);
Node *createNode(Node *newNode,uint32_t val);
int findAddRelativeVal(Node **node,int absoluteAddVal,int previousValue);
int printRelValFromSmallest(Node **rootPtr);
int findSmallestRelativeVal(Node **rootPtr);

#endif // _AVL_H
