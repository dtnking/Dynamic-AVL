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

void test_avlAdd_given_5_add_8(void){
  Node *root = &node5;
  initNode(&node5,NULL,NULL,0,5,5);
  initNode(&node8,NULL,NULL,0,8,8);
  createNode(&node6,6);

  avlRelativeAdd(&root,&node6);

  TEST_ASSERT_EQUAL_PTR(&node5,root);
  TEST_ASSERT_EQUAL_PTR(node6.cummulativeVal,6);

}
