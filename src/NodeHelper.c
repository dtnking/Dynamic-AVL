#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"

void initNode(Node *node, Node *left, Node *right, int bf,uint32_t rv, uint32_t cv){
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
  node->relativeVal = rv;
  node->cummulativeVal = cv;
}

Node *createNode(Node *newNode,uint32_t val){
  newNode->cummulativeVal = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *findAddRelativeVal(Node **node,int absoluteAddVal,int previousValue){
  Node *temp = NULL;
  if((*node)->right!=NULL){
    temp=findAddRelativeVal(&(*node)->right,absoluteAddVal,previousValue+(*node)->right->cummulativeVal);

  }
  if(previousValue == absoluteAddVal)
    return *node;
  return temp;
}

int printRelValFromSmallest(Node **rootPtr){
  if((*rootPtr)->left != NULL){
    printRelValFromSmallest(&(*rootPtr)->left);
  }
  printf("%d ,",(*rootPtr)->relativeVal);
  if((*rootPtr)->right != NULL){
     printRelValFromSmallest(&(*rootPtr)->right);
  }
}

int findSmallestRelativeVal(Node **rootPtr){
  if((*rootPtr)->left != NULL){
    findSmallestRelativeVal(&(*rootPtr)->left);
  }
  else
    return (*rootPtr)->cummulativeVal;
}

int findMostRightCummVal(Node **node,int absoluteAddVal,int previousValue){
  if((*node)->right!=NULL)
    findMostRightCummVal(&(*node)->right,absoluteAddVal,previousValue+(*node)->right->cummulativeVal);
  else
    return previousValue;
}

Node *findNearestReplacer(Node **rootPtr,int *heightFlag){
  Node *temp;
  if((*rootPtr) == NULL){
        *heightFlag = 1;
         return NULL;
    }
  if((*rootPtr)->left!=NULL){
    temp = findNearestReplacer(&(*rootPtr)->left,heightFlag);
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
