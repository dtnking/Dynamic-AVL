#ifndef _AVLRELATIVEREMOVE_H
#define _AVLRELATIVEREMOVE_H
#include "Rotate.h"
#include "NodeHelper.h"
#include "Node.h"
#include "stdio.h"

Node *avlRelativeRemove(Node **rootPtr,int delData);
Node *_avlRemove(Node **rootPtr,int nodeToDelete,int previousValue,int *heightFlag);

Node *avlRelativeRemoveSmallestRelative(Node **rootPtr,int delData);
Node *_avlRemoveSmallestRelative(Node **rootPtr,int absoluteDeleteValue,int previousValue,int *heightFlag);
Node *findNearest(Node **rootPtr,int *heightFlag);
#endif // _AVLRELATIVEREMOVE_H
