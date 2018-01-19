#include "avlRelativeRemove.h"

Node *avlRemoveWithoutAffectingRelativeVal(Node **rootPtr,int delData){
  int heightChange;
  int previousValue = 0;
  Node *dataRemove = _avlRemoveWithoutAffectingRelativeVal(rootPtr,delData,previousValue,&heightChange);
  if(dataRemove == NULL)
      Throw(createException("Couldn't find the node", NODE_NA));
  else
      return dataRemove;
}
Node *avlRelativeRemove(Node **rootPtr,int delData){
  int heightChange;
  int previousValue = 0;
  Node *dataRemove = _avlRelativeRemove(rootPtr,delData,previousValue,&heightChange);
  if(dataRemove == NULL)
      Throw(createException("Couldn't find the node", NODE_NA));
  else
      return dataRemove;
}

Node *_avlRemoveWithoutAffectingRelativeVal(Node **rootPtr,int absoluteDeleteValue,int previousValue,int *heightFlag){
  Node *temp;
  int absoluteValue;
  if(*rootPtr == NULL)
    return NULL;

  else{
    absoluteValue = previousValue + (*rootPtr)->cummulativeVal;
    if(absoluteDeleteValue == absoluteValue){
      if((*rootPtr)->left == NULL && (*rootPtr)->right == NULL){
      temp = *rootPtr;
      *rootPtr = NULL;
      *heightFlag = 1;
      return temp;
    }
      else if((*rootPtr)->left == NULL){
        temp = *rootPtr;
        (*rootPtr)->balanceFactor -= 1;
        *rootPtr = (*rootPtr)->right;
        *heightFlag = 1;
        return temp;
      }
      else if((*rootPtr)->right == NULL){
        temp = *rootPtr;
        (*rootPtr)->balanceFactor += 1;
        *rootPtr = (*rootPtr)->left;
        *heightFlag = 1;
        return temp;
      }
      else{
        temp = *rootPtr;
        *rootPtr = findNearestReplacer(&(*rootPtr)->right,heightFlag);

        if(*heightFlag == 1){
          temp->balanceFactor -= 1;
        }
        (*rootPtr)->balanceFactor = temp->balanceFactor;
        if(temp->right == NULL){
          (*rootPtr)->left = temp->left;
        }
        else{
          (*rootPtr)->left = temp->left;
          (*rootPtr)->right = temp->right;
        }
        if((*rootPtr)->balanceFactor == -2)
          *heightFlag = avlBalanceRightTree(rootPtr);
        else
          *heightFlag=1;

        if((*rootPtr)->balanceFactor != 0){
          *heightFlag = 0;
        }

      }
    }
    else{
      if(absoluteValue > absoluteDeleteValue){
        temp = _avlRemoveWithoutAffectingRelativeVal(&(*(rootPtr))->left,absoluteDeleteValue,previousValue,heightFlag);
        if(*heightFlag == 1){
          (*rootPtr)->balanceFactor+=1;
          *heightFlag = avlBalanceLeftTree(rootPtr);
        }
        else{
          *heightFlag = 0;
        }
        return temp;
      }
      else if(absoluteValue < absoluteDeleteValue){
        temp = _avlRemoveWithoutAffectingRelativeVal(&(*rootPtr)->right,absoluteDeleteValue,absoluteValue,heightFlag);
        if(*heightFlag == 1){
          (*rootPtr)->balanceFactor  -=1;
          *heightFlag = avlBalanceRightTree(rootPtr);
        }
        else{
          *heightFlag = 0;
        }
      }
    }
      return temp;
  }
}

Node *_avlRelativeRemove(Node **rootPtr,int absoluteDeleteValue,int previousValue,int *heightFlag){
  Node *temp;
  int absoluteValue;
  if(*rootPtr == NULL)
    return NULL;

  else{
    absoluteValue = previousValue + (*rootPtr)->cummulativeVal;
    if(absoluteDeleteValue == absoluteValue){
      if((*rootPtr)->left == NULL && (*rootPtr)->right == NULL){
      temp = *rootPtr;
      *rootPtr = NULL;
      *heightFlag = 1;
      return temp;
    }
      else if((*rootPtr)->left == NULL){
        temp = *rootPtr;
        (*rootPtr)->balanceFactor -= 1;
        *rootPtr = (*rootPtr)->right;
        (*rootPtr)->relativeVal += temp->relativeVal;
        (*rootPtr)->cummulativeVal += temp->cummulativeVal;
        *heightFlag = 1;
        return temp;
      }
      else if((*rootPtr)->right == NULL){
        temp = *rootPtr;
        (*rootPtr)->balanceFactor += 1;
        *rootPtr = (*rootPtr)->left;
        *heightFlag = 1;
        return temp;
      }
      else{
        temp = *rootPtr;
        *rootPtr = findNearestReplacer(&(*rootPtr)->right,heightFlag);
        if(*rootPtr != NULL){
          (*rootPtr)->relativeVal += temp->relativeVal;
          (*rootPtr)->cummulativeVal += temp->cummulativeVal;
        }
        if(*heightFlag == 1){
          temp->balanceFactor -= 1;
        }
        (*rootPtr)->balanceFactor = temp->balanceFactor;
        if(temp->right == NULL){
          (*rootPtr)->left = temp->left;
        }
        else{
          (*rootPtr)->left = temp->left;
          (*rootPtr)->right = temp->right;
        }
        if((*rootPtr)->balanceFactor == -2)
          *heightFlag = avlBalanceRightTree(rootPtr);
        else
          *heightFlag=1;

        if((*rootPtr)->balanceFactor != 0){
          *heightFlag = 0;
        }

      }
    }
    else{
      if(absoluteValue > absoluteDeleteValue){
        temp = _avlRelativeRemove(&(*(rootPtr))->left,absoluteDeleteValue,previousValue,heightFlag);
        if(temp == NULL)
          return NULL;
        if((*rootPtr)->left != NULL ){
          if((*rootPtr)->left->left == NULL && (*rootPtr)->left->right == NULL)
            if((*rootPtr)->left->cummulativeVal + (*rootPtr)->relativeVal != (*rootPtr)->cummulativeVal)
              (*rootPtr)->relativeVal += temp->relativeVal;
        }
        else
          (*rootPtr)->relativeVal += temp->relativeVal;

        if(*heightFlag == 1){
          (*rootPtr)->balanceFactor+=1;
          *heightFlag = avlBalanceLeftTree(rootPtr);
        }
        else{
          *heightFlag = 0;
        }
        return temp;
      }
      else if(absoluteValue < absoluteDeleteValue){
        temp = _avlRelativeRemove(&(*rootPtr)->right,absoluteDeleteValue,absoluteValue,heightFlag);
        if(temp == NULL){
          return NULL;
        }
        if(*heightFlag == 1){
          (*rootPtr)->balanceFactor  -=1;
          *heightFlag = avlBalanceRightTree(rootPtr);
        }
        else{
          *heightFlag = 0;
        }
      }
    }
      return temp;
  }
}

Node *removeSmallestRelativeVal(Node **rootPtr){
  Node *temp;
  int smallestRelativeVal;
  smallestRelativeVal = findSmallestRelativeVal(&(*rootPtr));

  avlRemoveWithoutAffectingRelativeVal(&(*rootPtr),smallestRelativeVal);
}
