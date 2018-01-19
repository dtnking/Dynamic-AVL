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

CEXCEPTION_T ex;

Node node1,node2,node3,node4,node5,node6,node7,node8,node9,node10;
Node node11,node12,node13,node14,node15,node16,node17,node18,node19,node20;

void setUp(void){}

void tearDown(void){}

// Given 5 add another 5  ------> Exception Thrown
void test_avlAdd_given_5_add_5_expected_exception_error_code_1(void){
  Node *root = &node5;
  initNode(&node5,NULL,NULL,0,5,5);
  Try{
  avlRelativeAdd(&root,&node5);
  }Catch(ex){
    TEST_ASSERT_EQUAL(1,ex->errorCode);
  }
  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,5,5);
}

//scenario 1
void test_avlAdd_given_5_add_8(void){
  Node *root = &node5;
  initNode(&node5,NULL,NULL,0,5,5);
  createNode(&node8,8);

  avlRelativeAdd(&root,&node8);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(NULL,&node8,1,&node5,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node8,3,3);
}

//scenario 2
void test_avlAdd_given_5_add_3(void){
  Node *root = &node5;
  initNode(&node5,NULL,NULL,0,5,5);
  createNode(&node3,3);

  avlRelativeAdd(&root,&node3);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node3,NULL,-1,&node5,2,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
}

//scenario 3
void test_avlAdd_given_5_3_7_add_1(void){
  Node *root = &node5;
  initNode(&node5,&node3,&node7,0,2,5);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node7,NULL,NULL,0,2,2);
  createNode(&node1,1);

  avlRelativeAdd(&root,&node1);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node7,-1,&node5,2,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,2,2);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node3,2,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1,1,1);
}

//scenario 4
void test_avlAdd_given_5_3_7_add_4(void){
  Node *root = &node5;
  initNode(&node5,&node3,&node7,0,2,5);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node7,NULL,NULL,0,2,2);
  createNode(&node4,4);

  avlRelativeAdd(&root,&node4);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node7,-1,&node5,1,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,&node4,1,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node4,1,1);
}

//scenario 5
void test_avlAdd_given_5_3_7_add_6(void){
  Node *root = &node5;
  initNode(&node5,&node3,&node7,0,2,5);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node7,NULL,NULL,0,2,2);
  createNode(&node6,6);

  avlRelativeAdd(&root,&node6);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node7,1,&node5,2,5);
  TEST_ASSERT_EQUAL_NODE(&node6,NULL,-1,&node7,1,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node6,1,1);
}

//scenario 6
void test_avlAdd_given_5_3_7_add_8(void){
  Node *root = &node5;
  initNode(&node5,&node3,&node7,0,2,5);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node7,NULL,NULL,0,2,2);
  createNode(&node8,8);

  avlRelativeAdd(&root,&node8);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node7,1,&node5,2,5);
  TEST_ASSERT_EQUAL_NODE(NULL,&node8,1,&node7,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node8,1,1);
}

//scenario 7
void test_avlAdd_given_5_3_add_2_expect_rotate_right(void){
  Node *root = &node5;
  initNode(&node5,&node3,NULL,-1,2,5);
  initNode(&node3,NULL,NULL,0,3,3);
  createNode(&node2,2);

  avlRelativeAdd(&root,&node2);

  TEST_ASSERT_EQUAL_PTR(&node3,root);
  TEST_ASSERT_EQUAL_NODE(&node2,&node5,0,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,2,2);
}

//scenario 8
void test_avlAdd_given_5_7_add_10_expect_rotate_left(void){
  Node *root = &node5;
  initNode(&node5,NULL,&node7,1,5,5);
  initNode(&node7,NULL,NULL,0,2,2);
  createNode(&node10,10);

  avlRelativeAdd(&root,&node10);

  TEST_ASSERT_EQUAL_PTR(&node7,root);
  TEST_ASSERT_EQUAL_NODE(&node5,&node10,0,&node7,2,7);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10,3,3);
}

//scenario 9
void test_avlAdd_given_5_3_add_4_expect_rotate_left_right(void){
  Node *root = &node5;
  initNode(&node5,&node3,NULL,-1,2,5);
  initNode(&node3,NULL,NULL,0,3,3);
  createNode(&node4,4);

  avlRelativeAdd(&root,&node4);

  TEST_ASSERT_EQUAL_PTR(&node4,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node5,0,&node4,1,4);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,1,1);
}

//scenario 10
void test_avlAdd_given_5_7_add_6_expect_rotate_right_left(void){
  Node *root = &node5;
  initNode(&node5,NULL,&node7,1,5,5);
  initNode(&node7,NULL,NULL,0,2,2);
  createNode(&node6,6);

  avlRelativeAdd(&root,&node6);

  TEST_ASSERT_EQUAL_PTR(&node6,root);
  TEST_ASSERT_EQUAL_NODE(&node5,&node7,0,&node6,1,6);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,1,1);
}

//scenario 11
void test_avlAdd_given_6_3_2_4_7_add_5_expect_rotate_left_right(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node7,-1,2,6);
  initNode(&node7,NULL,NULL,0,1,1);
  initNode(&node3,&node2,&node4,0,1,3);
  initNode(&node2,NULL,NULL,0,2,2);
  initNode(&node4,NULL,NULL,0,1,1);
  createNode(&node5,5);

  avlRelativeAdd(&root,&node5);

  TEST_ASSERT_EQUAL_PTR(&node4,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node6,0,&node4,1,4);
  TEST_ASSERT_EQUAL_NODE(&node2,NULL,-1,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,2,2);
  TEST_ASSERT_EQUAL_NODE(&node5,&node7,0,&node6,1,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,1,1);
}

//scenario 12
void test_avlAdd_given_6_3_2_5_7_add_4_expect_rotate_left_right(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node7,-1,2,6);
  initNode(&node7,NULL,NULL,0,1,1);
  initNode(&node3,&node2,&node5,0,1,3);
  initNode(&node2,NULL,NULL,0,2,2);
  initNode(&node5,NULL,NULL,0,2,2);
  createNode(&node4,4);

  avlRelativeAdd(&root,&node4);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node6,0,&node5,1,5);
  TEST_ASSERT_EQUAL_NODE(&node2,&node4,0,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,&node7,1,&node6,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node4,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,1,1);
}

//scenario 13
void test_avlAdd_given_6_3_9_8_10_add_7_expect_rotate_right_left(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node9,1,3,6);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node9,&node8,&node10,0,1,3);
  initNode(&node8,NULL,NULL,0,2,2);
  initNode(&node10,NULL,NULL,0,1,1);
  createNode(&node7,7);

  avlRelativeAdd(&root,&node7);

  TEST_ASSERT_EQUAL_PTR(&node8,root);
  TEST_ASSERT_EQUAL_NODE(&node6,&node9,0,&node8,1,8);
  TEST_ASSERT_EQUAL_NODE(&node3,&node7,0,&node6,3,6);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,&node10,1,&node9,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10,1,1);
}

//scenario 14
void test_avlAdd_given_6_3_8_10_11_add_9_expect_rotate_right_left(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node10,1,3,6);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node10,&node8,&node11,0,2,4);
  initNode(&node8,NULL,NULL,0,2,2);
  initNode(&node11,NULL,NULL,0,1,1);
  createNode(&node9,9);

  avlRelativeAdd(&root,&node9);

  TEST_ASSERT_EQUAL_PTR(&node8,root);
  TEST_ASSERT_EQUAL_NODE(&node6,&node10,0,&node8,2,8);
  TEST_ASSERT_EQUAL_NODE(&node3,NULL,-1,&node6,3,6);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(&node9,&node11,0,&node10,1,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node9,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node11,1,1);
}

//scenario 15
void test_avlAdd_given_6_3_8_9_10_add_9_expect_rotate_right_left(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node11,1,3,6);
  initNode(&node3,&node2,NULL,-1,1,3);
  initNode(&node2,NULL,NULL,0,2,2);
  initNode(&node11,&node8,&node12,-1,2,5);
  initNode(&node8,&node7,&node9,0,1,2);
  initNode(&node7,NULL,NULL,0,1,1);
  initNode(&node9,NULL,NULL,0,1,1);
  initNode(&node12,NULL,NULL,0,1,1);
  createNode(&node10,10);

  avlRelativeAdd(&root,&node10);

  TEST_ASSERT_EQUAL_PTR(&node6,root);
  TEST_ASSERT_EQUAL_NODE(&node3,&node9,1,&node6,3,6);
  TEST_ASSERT_EQUAL_NODE(&node2,NULL,-1,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,2,2);
  TEST_ASSERT_EQUAL_NODE(&node8,&node11,0,&node9,1,3);
  TEST_ASSERT_EQUAL_NODE(&node7,NULL,-1,&node8,1,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,1,1);
  TEST_ASSERT_EQUAL_NODE(&node10,&node12,0,&node11,1,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node12,1,1);
}


//scenario 16
void test_avlAdd_given_6_3_2_5_7_add_1_expect_rotate_right(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node7,-1,1,6);
  initNode(&node7,NULL,NULL,0,1,1);
  initNode(&node3,&node2,&node5,0,1,3);
  initNode(&node2,NULL,NULL,0,2,2);
  initNode(&node5,NULL,NULL,0,2,2);
  createNode(&node1,1);

  avlRelativeAdd(&root,&node1);

  TEST_ASSERT_EQUAL_PTR(&node3,root);
  TEST_ASSERT_EQUAL_NODE(&node2,&node6,0,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node2,1,2);
  TEST_ASSERT_EQUAL_NODE(&node5,&node7,0,&node6,1,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,1,1);
}

//scenario 17
void test_avlAdd_given_6_3_1_5_7_add_2_expect_rotate_right(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node7,-1,1,6);
  initNode(&node7,NULL,NULL,0,1,1);
  initNode(&node3,&node1,&node5,0,2,3);
  initNode(&node1,NULL,NULL,0,1,1);
  initNode(&node5,NULL,NULL,0,2,2);
  createNode(&node2,2);

  avlRelativeAdd(&root,&node2);

  TEST_ASSERT_EQUAL_PTR(&node3,root);
  TEST_ASSERT_EQUAL_NODE(&node1,&node6,0,&node3,1,3);
  TEST_ASSERT_EQUAL_NODE(NULL,&node2,1,&node1,1,1);
  TEST_ASSERT_EQUAL_NODE(&node5,&node7,0,&node6,1,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node2,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,1,1);
}

//scenario 18
void test_avlAdd_given_6_3_8_10_11_add_15_expect_rotate_left(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node10,1,3,6);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node10,&node8,&node11,0,2,4);
  initNode(&node8,NULL,NULL,0,2,2);
  initNode(&node11,NULL,NULL,0,1,1);
  createNode(&node15,15);

  avlRelativeAdd(&root,&node15);

  TEST_ASSERT_EQUAL_PTR(&node10,root);
  TEST_ASSERT_EQUAL_NODE(&node6,&node11,0,&node10,2,10);
  TEST_ASSERT_EQUAL_NODE(&node3,&node8,0,&node6,3,6);
  TEST_ASSERT_EQUAL_NODE(NULL,&node15,1,&node11,1,1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node8,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node15,4,4);

}

//scenario 19
void test_avlAdd_given_6_3_8_10_13_add_11_expect_rotate_left(void){
  Node *root = &node6;
  initNode(&node6,&node3,&node10,1,3,6);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node10,&node8,&node13,0,2,4);
  initNode(&node8,NULL,NULL,0,2,2);
  initNode(&node13,NULL,NULL,0,3,3);
  createNode(&node11,11);

  avlRelativeAdd(&root,&node11);

  TEST_ASSERT_EQUAL_PTR(&node10,root);
  TEST_ASSERT_EQUAL_NODE(&node6,&node13,0,&node10,2,10);
  TEST_ASSERT_EQUAL_NODE(&node3,&node8,0,&node6,3,6);
  TEST_ASSERT_EQUAL_NODE(&node11,NULL,-1,&node13,2,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node3,3,3);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node8,2,2);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node11,1,1);
}
