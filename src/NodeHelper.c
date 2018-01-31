#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"

extern Node node1,node2,node3,node4,node5,node6,node7,node8,node9,node10;
extern Node node11,node12,node13,node14,node15,node16,node17,node18,node19,node20;
extern Node node28,node30,node40,node80,node31,node22,node34,node37,node45,node25;

void initNode(Node *node, Node *left, Node *right, int bf,uint32_t rv, uint32_t cv){
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
  node->relativeVal = rv;
  node->cummulativeVal = cv;
}

void initPrimitiveNode(){
  createNode(&node1,1);
  createNode(&node2,2);
  createNode(&node3,3);
  createNode(&node4,4);
  createNode(&node5,5);
  createNode(&node6,6);
  createNode(&node7,7);
  createNode(&node8,8);
  createNode(&node9,9);
  createNode(&node10,10);
  createNode(&node11,11);
  createNode(&node12,12);
  createNode(&node13,13);
  createNode(&node14,14);
  createNode(&node15,15);
  createNode(&node16,16);
  createNode(&node17,17);
  createNode(&node18,18);
  createNode(&node19,19);
  createNode(&node20,20);
  createNode(&node22,22);
  createNode(&node25,25);
  createNode(&node28,28);
  createNode(&node30,30);
  createNode(&node31,31);
  createNode(&node34,34);
  createNode(&node37,37);
  createNode(&node40,40);
  createNode(&node45,45);
  createNode(&node80,80);
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
