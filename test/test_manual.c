#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"
#include "NodeVerifier.h"
#include <stdint.h>
#include <stdio.h>
#include "Rotate.h"
#include "Exception.h"
#include "avlRelativeAdd.h"
#include "CExceptionConfig.h"

Node node1,node2,node3,node4,node5,node6,node7,node8,node9,node10;
Node node11,node12,node13,node14,node15,node16,node17,node18,node19,node20;
Node node28,node30,node40,node80,node31,node22,node34,node37,node45,node25;

void setUp(void){}

void tearDown(void){}

void test_manual_add_4_2_15_10_30_80_28_40_3(void){
  Node *root = NULL;
  createNode(&node4,4);
  createNode(&node2,2);
  createNode(&node15,15);
  createNode(&node10,10);
  createNode(&node30,30);
  createNode(&node80,80);
  createNode(&node28,28);
  createNode(&node40,40);
  createNode(&node3,3);

  avlRelativeAdd(&root,&node4);
  avlRelativeAdd(&root,&node2);
  avlRelativeAdd(&root,&node15);
  avlRelativeAdd(&root,&node10);
  avlRelativeAdd(&root,&node30);
  avlRelativeAdd(&root,&node80);
  avlRelativeAdd(&root,&node28);
  avlRelativeAdd(&root,&node40);
  avlRelativeAdd(&root,&node3);

  printRelValFromSmallest(&root);
}


void test_manual_given_random_node(void){
  Node *root = NULL;
  createNode(&node3,3);
  createNode(&node1,1);
  createNode(&node20,20);
  createNode(&node2,2);
  createNode(&node6,6);
  createNode(&node31,31);
  createNode(&node22,22);
  createNode(&node34,34);
  createNode(&node14,14);
  createNode(&node37,37);
  createNode(&node9,9);
  createNode(&node40,40);
  createNode(&node45,45);
  createNode(&node25,25);
  createNode(&node8,8);
  createNode(&node17,17);

  avlRelativeAdd(&root,&node3);
  avlRelativeAdd(&root,&node1);
  avlRelativeAdd(&root,&node20);
  avlRelativeAdd(&root,&node2);
  avlRelativeAdd(&root,&node6);
  avlRelativeAdd(&root,&node31);
  avlRelativeAdd(&root,&node22);
  avlRelativeAdd(&root,&node34);
  avlRelativeAdd(&root,&node14);
  avlRelativeAdd(&root,&node37);
  avlRelativeAdd(&root,&node9);
  avlRelativeAdd(&root,&node40);
  avlRelativeAdd(&root,&node45);
  avlRelativeAdd(&root,&node25);
  avlRelativeAdd(&root,&node8);
  avlRelativeAdd(&root,&node17);

  printRelValFromSmallest(&root);
}
