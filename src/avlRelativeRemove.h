#ifndef _AVLRELATIVEREMOVE_H
#define _AVLRELATIVEREMOVE_H
#include "Rotate.h"
#include "NodeHelper.h"
#include "Node.h"
#include "Exception.h"
#include "CException.h"
#include "CExceptionConfig.h"

Node *avlRelativeRemove(Node **rootPtr,int delData);
Node *_avlRelativeRemove(Node **rootPtr,int nodeToDelete,int previousValue,int *heightFlag);

Node *avlRemoveWithoutAffectingRelativeVal(Node **rootPtr,int delData);
Node *_avlRemoveWithoutAffectingRelativeVal(Node **rootPtr,int absoluteDeleteValue,int previousValue,int *heightFlag);

Node *removeSmallestRelativeVal(Node **rootPtr);

#endif // _AVLRELATIVEREMOVE_H
