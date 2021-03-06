#ifndef _ROTATE_H
#define _ROTATE_H
#include "Node.h"

Node *rotateRight(Node *node);
Node *rotateLeft(Node *node);
Node *rotateLeftRight(Node *node);
Node *rotateRightLeft(Node *node);
int avlBalanceRightTree(Node **rootPtr);
int avlBalanceLeftTree(Node **rootPtr);

#endif // _ROTATE_H
