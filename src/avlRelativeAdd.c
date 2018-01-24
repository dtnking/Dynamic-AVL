#include "avlRelativeAdd.h"


void avlRelativeAdd(Node **root, Node *nodeToAdd){
  int previousValue = 0;
  int cummulativeValue = nodeToAdd->cummulativeVal;
  _avlRelativeAdd(root,nodeToAdd,previousValue,cummulativeValue);
}

int _avlRelativeAdd(Node **rootPtr, Node *nodeToAdd, int previousValue, int cummulativeValue){
  int heightChanged;
  int absoluteValue;
  int addCummulativeVal = nodeToAdd->cummulativeVal;
  if(*rootPtr == NULL){
    (*rootPtr) = nodeToAdd;
    nodeToAdd->cummulativeVal = cummulativeValue;
    nodeToAdd->relativeVal = cummulativeValue;
    nodeToAdd->balanceFactor = 0;
    return 1;
  }else{
    absoluteValue = previousValue + (*rootPtr)->cummulativeVal;
    if (absoluteValue < nodeToAdd->cummulativeVal){
      heightChanged = _avlRelativeAdd(&(*rootPtr)->right,nodeToAdd,absoluteValue,nodeToAdd->cummulativeVal-absoluteValue);
      if(heightChanged==1){
          (*rootPtr)->balanceFactor += 1 ;
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

  else if(absoluteValue > nodeToAdd->cummulativeVal){
    heightChanged = _avlRelativeAdd(&(*rootPtr)->left,nodeToAdd,previousValue,nodeToAdd->cummulativeVal- previousValue);
    if((*rootPtr)->left != NULL){
      if((*rootPtr)->left->cummulativeVal == addCummulativeVal)
        (*rootPtr)->relativeVal -= cummulativeValue;
      else if((*rootPtr)->left->cummulativeVal + previousValue == addCummulativeVal){
        if(heightChanged != 0)
          (*rootPtr)->relativeVal -= cummulativeValue;
      }
      else{
        if((*rootPtr)->left->right !=NULL){
          Node *addRelativeVal = findAddRelativeVal(&(*rootPtr)->left,addCummulativeVal,previousValue+(*rootPtr)->left->cummulativeVal);
          if(addRelativeVal!=NULL){
            if(heightChanged != 0)      //  To make sure no rotation occur
              (*rootPtr)->relativeVal -= addRelativeVal->relativeVal;                     //
            else{
            int valToCompare = findMostRightCummVal(&(*rootPtr)->left,addCummulativeVal,previousValue+(*rootPtr)->left->cummulativeVal);
              if(valToCompare == addCummulativeVal)
                (*rootPtr)->relativeVal -= addRelativeVal->relativeVal;
            }
          }
        }
      }
    }


    if(heightChanged==1){
      (*rootPtr)->balanceFactor -= 1;
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
  else
    Throw(createException("Node to add is already exist", NODE_ADD_EXIST));
}
}
