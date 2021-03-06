#ifndef _AVLRELATIVEADD_H
#define _AVLRELATIVEADD_H
#include "Rotate.h"
#include "NodeHelper.h"
#include "Node.h"
#include "Exception.h"
#include "CException.h"
#include "CExceptionConfig.h"


void avlRelativeAdd(Node **root, Node *nodeToAdd);
int _avlRelativeAdd(Node **rootPtr, Node *nodeToAdd, int previousValue, int cummulativeValue);
#endif // _AVLRELATIVEADD_H
