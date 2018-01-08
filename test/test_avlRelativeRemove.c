#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"
#include "NodeVerifier.h"
#include <stdint.h>
#include <stdio.h>
#include "Rotate.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "avlRelativeRemove.h"

CEXCEPTION_T ex;

Node node1,node2,node3,node4,node5,node6,node7,node8,node9,node10;
Node node11,node12,node13,node14,node15,node16,node17,node18,node19,node20;

void setUp(void){}

void tearDown(void){}

//scenario 1
void test_avlRelativeRemove_given_5_2_7_6_10_remove_7(void){
  Node *root = &node5;
  initNode(&node5,&node2,&node7,1,3,5);
  initNode(&node2,NULL,NULL,0,2,2);
  initNode(&node7,&node6,&node10,0,1,2);
  initNode(&node6,NULL,NULL,0,1,1);
  initNode(&node10,NULL,NULL,0,3,3);

  avlRelativeRemove(&root,7,0);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node2,&node10,1,&node5,3,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,2,2);
  TEST_ASSERT_EQUAL_NODE(&node6,NULL,-1,&node10,4,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node6,1,1);
}

//scenario 2
void test_avlRelativeRemove_given_5_2_1_7_6_10_9_remove_7(void){
  Node *root = &node5;
  initNode(&node5,&node2,&node7,1,3,5);
  initNode(&node2,&node1,NULL,-1,1,2);
  initNode(&node1,NULL,NULL,0,1,1);
  initNode(&node7,&node6,&node10,1,1,2);
  initNode(&node6,NULL,NULL,0,1,1);
  initNode(&node10,&node9,NULL,-1,1,3);
  initNode(&node9,NULL,NULL,0,2,2);

  avlRelativeRemove(&root,7,0);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node2,&node9,0,&node5,3,5);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node2,1,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(&node6,&node10,0,&node9,3,4);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node6,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10,1,1);
}

//scenario 3
void test_avlRelativeRemove_given_9_3_1_7_4_11_12_remove_3(void){
  Node *root = &node9;
  initNode(&node9,&node3,&node11,-1,2,9);
  initNode(&node3,&node1,&node7,1,2,3);
  initNode(&node11,NULL,&node12,1,2,2);
  initNode(&node1,NULL,NULL,0,1,1);
  initNode(&node7,&node4,NULL,-1,3,4);
  initNode(&node12,NULL,NULL,0,1,1);
  initNode(&node4,NULL,NULL,0,1,1);

  avlRelativeRemove(&root,3,0);

  TEST_ASSERT_EQUAL_PTR(&node9,root);
  TEST_ASSERT_EQUAL_NODE(&node4,&node11,0,&node9,2,9);
  TEST_ASSERT_EQUAL_NODE(&node1,&node7,0,&node4,3,4);
  TEST_ASSERT_EQUAL_NODE(NULL,&node12,1,&node11,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node12,1,1);
}

//scenario 4
void test_avlRelativeRemove_given_9_3_1_7_11_12_remove_3(void){
  Node *root = &node9;
  initNode(&node9,&node3,&node11,0,2,9);
  initNode(&node3,&node1,&node7,0,2,3);
  initNode(&node11,NULL,&node12,1,2,2);
  initNode(&node1,NULL,NULL,0,1,1);
  initNode(&node7,NULL,NULL,0,4,4);
  initNode(&node12,NULL,NULL,0,1,1);

  avlRelativeRemove(&root,3,0);

  TEST_ASSERT_EQUAL_PTR(&node9,root);
  TEST_ASSERT_EQUAL_NODE(&node7,&node11,0,&node9,2,9);
  TEST_ASSERT_EQUAL_NODE(NULL,&node12,1,&node11,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node7,6,7);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node12,1,1);
}

//scenario 5
void test_avlRelativeRemove_given_5_3_remove_3(void){
  Node *root = &node5;
  initNode(&node5,&node3,NULL,-1,2,5);
  initNode(&node3,NULL,NULL,0,3,3);

  avlRelativeRemove(&root,3,0);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,5,5);
}

//scenario 6
void test_avlRelativeRemove_given_5_3_2_10_remove_3(void){
  Node *root = &node5;
  initNode(&node5,&node3,&node10,-1,2,5);
  initNode(&node3,&node2,NULL,-1,1,3);
  initNode(&node2,NULL,NULL,0,2,2);
  initNode(&node10,NULL,NULL,0,5,5);

  avlRelativeRemove(&root,3,0);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node2,&node10,0,&node5,3,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10,5,5);
}

//scenario 7
void test_avlRelativeRemove_given_5_3_remove_5(void){
  Node *root = &node5;
  initNode(&node5,&node3,NULL,-1,2,5);
  initNode(&node3,NULL,NULL,0,3,3);

  avlRelativeRemove(&root,5,0);

  TEST_ASSERT_EQUAL_PTR(&node3,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
}

//scenario 8
void test_avlRelativeRemove_given_5_3_7_4_remove_4(void){
  Node *root = &node5;
  initNode(&node5,&node3,&node7,-1,1,5);
  initNode(&node3,NULL,&node4,1,3,3);
  initNode(&node4,NULL,NULL,0,1,1);
  initNode(&node7,NULL,NULL,0,2,2);

  avlRelativeRemove(&root,4,0);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node7,0,&node5,2,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,2,2);
}

//scenario 9
void test_avlRelativeRemove_given_9_3_1_7_11_12_remove_1(void){
  Node *root = &node9;
  initNode(&node9,&node3,&node11,0,2,9);
  initNode(&node3,&node1,&node7,0,2,3);
  initNode(&node11,NULL,&node12,1,2,2);
  initNode(&node1,NULL,NULL,0,1,1);
  initNode(&node7,NULL,NULL,0,4,4);
  initNode(&node12,NULL,NULL,0,1,1);

  avlRelativeRemove(&root,1,0);

  TEST_ASSERT_EQUAL_PTR(&node9,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node11,0,&node9,2,9);
  TEST_ASSERT_EQUAL_NODE(NULL,&node12,1,&node11,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,&node7,-1,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node7,4,4);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node12,1,1);
}
