#include "avlRelativeAdd.h"
#include "Node.h"



int avlRelativeAdd(Node **rootPtr, Node *nodeToAdd, int previousValue, int cummulativeValue){
  int heightChanged;
  int cummulativeRightTemp;
  int temp = nodeToAdd->cummulativeVal;
  if(*rootPtr == NULL){
    (*rootPtr) = nodeToAdd;
    nodeToAdd->cummulativeVal = cummulativeValue;
    nodeToAdd->relativeVal = cummulativeValue;
    nodeToAdd->balanceFactor = 0;

    return 1;
  }else{
    cummulativeRightTemp = previousValue + (*rootPtr)->cummulativeVal;
    if (cummulativeRightTemp < nodeToAdd->cummulativeVal){
      // if((*rootPtr)->right != NULL){
      //   previousValue += (*rootPtr)->right->cummulativeVal;
      // }
      // else{
      //   previousValue = nodeToAdd->cummulativeVal - previousValue;
      // }
      heightChanged = avlRelativeAdd(&(*rootPtr)->right,nodeToAdd,cummulativeRightTemp,nodeToAdd->cummulativeVal-cummulativeRightTemp);
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
  else if(cummulativeRightTemp > nodeToAdd->cummulativeVal){
    // if((*rootPtr)->left == NULL){
    //   (*rootPtr)->relativeVal -= cummulativeValue;
    // }
    heightChanged = avlRelativeAdd(&(*rootPtr)->left,nodeToAdd,previousValue,nodeToAdd->cummulativeVal- previousValue);
      if((*rootPtr)->left != NULL){
        if((*rootPtr)->left->cummulativeVal == temp || (*rootPtr)->left->cummulativeVal + previousValue == temp)
        (*rootPtr)->relativeVal -= cummulativeValue;
      }
      // if(cummulativeRightTemp > nodeToAdd->cummulativeVal && (*rootPtr)->left->left == NULL && (*rootPtr)->left->right == NULL)

      // if((*rootPtr)->left->right!=NULL){
      //   if((*rootPtr)->left->right->left == NULL && (*rootPtr)->left->right->right == NULL \
      //     && (*rootPtr)->left->right->relativeVal + (*rootPtr)->left->cummulativeVal == temp){
      //           (*rootPtr)->relativeVal -= (*rootPtr)->left->right->relativeVal;
      //   }
      // }

      if((*rootPtr)->left->right !=NULL){
        int absVal = findNode(&(*rootPtr)->left,nodeToAdd,temp,previousValue);
        (*rootPtr)->relativeVal -= absVal;
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



      //Throw(createException("Node to add is already exist", NODE_ADD_EXIST));
  }

}
