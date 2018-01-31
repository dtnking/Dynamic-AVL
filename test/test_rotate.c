#include "unity.h"
#include "Rotate.h"
#include "NodeHelper.h"
#include "NodeVerifier.h"

void setUp(void){}

void tearDown(void){}

/**
 *              15                   7
 *             /                    / \
 *           7       ----->       5   15
 *          / \                      /
 *        5   10                   10
 *
 */
void test_rotate_right_expected_root_cummulative_value_minus_with_childs(void){
  Node *root;
  initNode(&node15,&node7,NULL,-2,5,15);
  initNode(&node7,&node5,&node10,0,2,7);
  initNode(&node5,NULL,NULL,0,5,5);
  initNode(&node10,NULL,NULL,0,3,3);

  root = rotateRight(&node15);
  TEST_ASSERT_EQUAL_PTR(&node7,root);
  TEST_ASSERT_EQUAL_NODE(&node5,&node15,0,&node7,2,7);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-2,&node15,5,8);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5,5,5);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10,3,3);
}

/**
 *            5                      11
 *             \                    /  \
 *             11       ----->     5   13
 *            /  \                  \
 *           7   13                 7
 *
 */
 void test_rotate_left_expected_child_cummulative_value_added_with_root(void){
   Node *root;
   initNode(&node5,NULL,&node11,2,5,5);
   initNode(&node11,&node7,&node13,0,4,6);
   initNode(&node7,NULL,NULL,0,2,2);
   initNode(&node13,NULL,NULL,0,2,2);

   root = rotateLeft(&node5);
   TEST_ASSERT_EQUAL_PTR(&node11,root);
   TEST_ASSERT_EQUAL_NODE(&node5,&node13,0,&node11,4,11);
   TEST_ASSERT_EQUAL_NODE(NULL,&node7,2,&node5,5,5);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node13,2,2);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node7,2,2);
 }
