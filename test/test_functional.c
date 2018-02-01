#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"
#include "NodeVerifier.h"
#include <stdint.h>
#include <stdio.h>
#include "Rotate.h"
#include "Exception.h"
#include "avlRelativeAdd.h"
#include "avlRelativeRemove.h"
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

  TEST_ASSERT_EQUAL_PTR(&node15,root);
  TEST_ASSERT_EQUAL_NODE(&node4,&node30,0,&node15,5,15);
  TEST_ASSERT_EQUAL_NODE(&node2,&node10,-1,&node4,1,4);
  TEST_ASSERT_EQUAL_NODE(&node28,&node80,1,&node30,2,15);
  TEST_ASSERT_EQUAL_NODE(NULL,&node3,1,&node2,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10,6,6);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node28,13,13);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,-1,&node80,40,50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40,10,10);
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

  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node37,-1,&node20,3,20);
  TEST_ASSERT_EQUAL_NODE(&node1,&node9,1,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(&node31,&node40,0,&node37,3,17);
  TEST_ASSERT_EQUAL_NODE(NULL,&node2,1,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(&node6,&node14,1,&node9,3,6);
  TEST_ASSERT_EQUAL_NODE(&node22,&node34,0,&node31,9,11);
  TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node6,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,&node17,1,&node14,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node22,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node34,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node17,3,3);

  avlRelativeRemove(&root,9);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node37,0,&node20,3,20);
  TEST_ASSERT_EQUAL_NODE(&node1,&node14,0,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(&node31,&node40,0,&node37,3,17);
  TEST_ASSERT_EQUAL_NODE(NULL,&node2,1,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(&node22,&node34,0,&node31,9,11);
  TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node6,3,3);
  TEST_ASSERT_EQUAL_NODE(&node6,&node17,0,&node14,8,11);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node22,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node34,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node17,3,3);

  avlRelativeRemove(&root,20);
  TEST_ASSERT_EQUAL_PTR(&node22,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node37,0,&node22,5,22);
  TEST_ASSERT_EQUAL_NODE(&node1,&node14,0,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(&node31,&node40,0,&node37,3,15);
  TEST_ASSERT_EQUAL_NODE(NULL,&node2,1,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,&node34,1,&node31,9,9);
  TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node6,3,3);
  TEST_ASSERT_EQUAL_NODE(&node6,&node17,0,&node14,8,11);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node34,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node17,3,3);

  avlRelativeRemove(&root,2);
  TEST_ASSERT_EQUAL_PTR(&node22,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node37,0,&node22,5,22);
  TEST_ASSERT_EQUAL_NODE(&node1,&node14,1,&node3,2,3);
  TEST_ASSERT_EQUAL_NODE(&node31,&node40,0,&node37,3,15);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,&node34,1,&node31,9,9);
  TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node6,3,3);
  TEST_ASSERT_EQUAL_NODE(&node6,&node17,0,&node14,8,11);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node34,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node17,3,3);

  avlRelativeRemove(&root,37);
  TEST_ASSERT_EQUAL_PTR(&node22,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node40,0,&node22,5,22);
  TEST_ASSERT_EQUAL_NODE(&node1,&node14,1,&node3,2,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,&node34,1,&node31,9,9);
  TEST_ASSERT_EQUAL_NODE(&node31,&node45,-1,&node40,6,18);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node6,3,3);
  TEST_ASSERT_EQUAL_NODE(&node6,&node17,0,&node14,8,11);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node34,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node17,3,3);

  avlRelativeRemove(&root,3);
  TEST_ASSERT_EQUAL_PTR(&node22,root);
  TEST_ASSERT_EQUAL_NODE(&node6,&node40,0,&node22,5,22);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,&node34,1,&node31,9,9);
  TEST_ASSERT_EQUAL_NODE(&node31,&node45,-1,&node40,6,18);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,1,1);
  TEST_ASSERT_EQUAL_NODE(&node1,&node14,1,&node6,5,6);
  TEST_ASSERT_EQUAL_NODE(NULL,&node17,1,&node14,8,8);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node34,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node17,3,3);
}
