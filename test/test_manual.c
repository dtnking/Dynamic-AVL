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

void setUp(void){
  initPrimitiveNode();
}

void tearDown(void){}

void test_manual_add_4_2_15_10_30_80_28_40_3(void){
  Node *root = NULL;

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
  avlRelativeAdd(&root,&node17);

  printRelValFromSmallest(&root);
}
