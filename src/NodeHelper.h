#ifndef _NODEHELPER_H
#define _NODEHELPER_H
#include "Rotate.h"

Node node1,node2,node3,node4,node5,node6,node7,node8,node9,node10;
Node node11,node12,node13,node14,node15,node16,node17,node18,node19,node20;
Node node28,node30,node40,node80,node31,node22,node34,node37,node45,node25;

void initNode(Node *node, Node *left, Node *right, int bf,uint32_t rv, uint32_t cv);
Node *createNode(Node *newNode,uint32_t val);
Node *findAddRelativeVal(Node **node,int absoluteAddVal,int previousValue);
int printRelValFromSmallest(Node **rootPtr);
int findSmallestRelativeVal(Node **rootPtr);
Node *findNearestReplacer(Node **rootPtr,int *heightFlag);
void initPrimitiveNode();

#endif // _AVL_H
