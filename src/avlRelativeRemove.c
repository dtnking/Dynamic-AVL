#include "avlRelativeRemove.h"

Node *avlRelativeRemove(Node **rootPtr,int delData){
  int heightChange;
  int previousValue = 0;
  Node *dataRemove = _avlRemove(rootPtr,delData,previousValue,&heightChange);
    if(dataRemove == NULL)
      printf("Couldn't find the node");
    else
      return dataRemove;
}

Node *_avlRemove(Node **rootPtr,int absoluteDeleteValue,int previousValue,int *heightFlag){
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
        *rootPtr = findNearest(&(*rootPtr)->right,heightFlag);
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
        temp = _avlRemove(&(*(rootPtr))->left,absoluteDeleteValue,previousValue,heightFlag);
        if((*rootPtr)->left != NULL ){

          if((*rootPtr)->left->left == NULL && (*rootPtr)->left->right == NULL  )
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
        temp = _avlRemove(&(*rootPtr)->right,absoluteDeleteValue,absoluteValue,heightFlag);
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

Node *findNearest(Node **rootPtr,int *heightFlag){
  Node *temp;
  if((*rootPtr) == NULL){
        *heightFlag = 1;
         return NULL;
    }
  if((*rootPtr)->left!=NULL){
    temp = findNearest(&(*rootPtr)->left,heightFlag);
    if(*heightFlag == 1){
      (*rootPtr)->cummulativeVal = (*rootPtr)->relativeVal;
      (*rootPtr)->balanceFactor += 1;
      *heightFlag = avlBalanceLeftTree(rootPtr);
      if((*rootPtr)->balanceFactor != 0)
        *heightFlag = 0;
    }
    if(temp->right != NULL){
      (*rootPtr)->left = temp->right;
      temp->right = NULL;
    }
    return temp;
  }
  else{
    temp = (*rootPtr);
    (*rootPtr) = NULL;
    *heightFlag = 1;
    return temp;
  }
}
