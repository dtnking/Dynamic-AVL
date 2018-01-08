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

int findNode(Node **node,Node *nodeToAdd,int absoluteAddVal,int previousValue){
  if((*node)->right!=NULL){
    if((*node)->right->relativeVal + previousValue + (*node)->cummulativeVal != absoluteAddVal){
      findNode(&(*node)->right,nodeToAdd,absoluteAddVal,previousValue+(*node)->right->cummulativeVal);
    }
    else{
      return ((*node)->right->relativeVal);
    }
  }
  return (*node)->relativeVal;
}
