#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>

typedef struct Node Node;
struct Node{
  Node *left;
  Node *right;
  int balanceFactor;
  int height;
  int relativeVal;
  int cummulativeVal;
};


#endif // _NODE_H
