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

int findAddRelativeVal(Node **node,int absoluteAddVal,int previousValue){
  int storeV=0;
  if((*node)->right!=NULL){
    storeV=findAddRelativeVal(&(*node)->right,absoluteAddVal,previousValue+(*node)->right->relativeVal);

  }
  if(previousValue == absoluteAddVal)
    return (*node)->relativeVal;
  return storeV;
}

double printRelValFromSmallest(Node **rootPtr){
  if((*rootPtr)->left != NULL){
    printRelValFromSmallest(&(*rootPtr)->left);
  }
  if((*rootPtr)->right != NULL){
    printf("%d ,",(*rootPtr)->relativeVal);
    return printRelValFromSmallest(&(*rootPtr)->right);
  }
  return printf("%d ,",(*rootPtr)->relativeVal);
}
