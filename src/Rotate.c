#include "Rotate.h"

Node *rotateRight(Node *node){
  Node *temp = node->left;
  node->left = temp->right;
  temp->right = node;
  return temp;
}

Node *rotateLeft(Node *node){
  Node *temp = node->right;
  node->right = temp->left;
  temp->left = node;
  return temp;
}

Node *rotateLeftRight(Node *node){
  node->left = rotateLeft(node->left);
  Node *temp = rotateRight(node);
  return temp;
}

Node *rotateRightLeft(Node *node){
  node->right = rotateRight(node->right);
  Node *temp = rotateLeft(node);
  return temp;
}

int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;

  if((*rootPtr)->balanceFactor  <= 1)
    return 1;

  if(node->right->balanceFactor == 1 ){
    node->balanceFactor = 0;
    node->right->balanceFactor = 0;
    *rootPtr = rotateLeft(*rootPtr);
    return 1;
    }
  else if(node->right->balanceFactor == 0){
    node->balanceFactor = 1;
    node->right->balanceFactor = -1;
    *rootPtr = rotateLeft(*rootPtr);
    return 0;
    }
  else if(node->right->balanceFactor == -1){
    if(node->right->left->balanceFactor == -1){
      node->balanceFactor = 0;
      node->right->balanceFactor = 1;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      return 1;
      }
    else if(node->right->left->balanceFactor == 0){
      node->balanceFactor = 0;
      node->right->balanceFactor = 0;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      return 1;
      }
    else if(node->right->left->balanceFactor == 1){
      node->balanceFactor = -1;
      node->right->balanceFactor = 0;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      return 1;
      }
    }
}

int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;



  if((*rootPtr)->balanceFactor >= -1)
    return 1;


  if(node->left->balanceFactor == -1 ){
    node->balanceFactor = 0;
    node->left->balanceFactor = 0;
    *rootPtr = rotateRight(*rootPtr);
    return 1;
    }
  else if(node->left->balanceFactor == 0){
    node->balanceFactor = -1;
    node->left->balanceFactor = 1;
    *rootPtr = rotateRight(*rootPtr);
    return 0;
    }
  else if(node->left->balanceFactor ==1){
    if(node->left->right->balanceFactor == 1){
      node->balanceFactor = 0;
      node->left->balanceFactor = -1;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      return 1;
      }
    else if(node->left->right->balanceFactor == 0){
      node->balanceFactor = 0;
      node->left->balanceFactor = 0;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      return 1;
      }
    else if(node->left->right->balanceFactor == -1){
      node->balanceFactor = 1;
      node->left->balanceFactor = 0;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      return 1;
      }

  }
  return 0;
}
