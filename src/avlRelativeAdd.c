#include "avlRelativeAdd.h"
#include "Node.h"



int avlRelativeAdd(Node **rootPtr, Node *nodeToAdd){
  int heightChanged;

if(*rootPtr == NULL){
  *rootPtr = nodeToAdd;
  return 1;
} else {
  if ((*rootPtr)->cummulativeVal < nodeToAdd->cummulativeVal){
      heightChanged = avlRelativeAdd(&(*rootPtr)->left,nodeToAdd);
      if(heightChanged==1){
        (*rootPtr)->balanceFactor -= 1 ;
        if((*rootPtr)->balanceFactor==0)
          return 0;
      }
      else
        return 0;

    if((*rootPtr)->balanceFactor !=-2)
      return 1;

    if(avlBalanceRightTree(&(*rootPtr))==1)
      return 0;
    else
      return 1;
  }
  else if((*rootPtr)->cummulativeVal > nodeToAdd->cummulativeVal){
      heightChanged = avlRelativeAdd(&(*rootPtr)->right,nodeToAdd);
      if(heightChanged==1){
        (*rootPtr)->balanceFactor += 1;
        if((*rootPtr)->balanceFactor==0)
          return 0;
        }
      else
        return 0;
    if((*rootPtr)->balanceFactor != 2)
      return 1;

    if(avlBalanceLeftTree(&(*rootPtr))==1)
      return 0;
    else
      return 1;
    }

      //Throw(createException("Node to add is already exist", NODE_ADD_EXIST));
  }
}
