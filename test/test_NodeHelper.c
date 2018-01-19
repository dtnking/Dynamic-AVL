#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"
#include "avlRelativeRemove.h"
#include "Rotate.h"

Node node1,node2,node3,node4,node5,node6,node7,node8,node9,node10;
Node node11,node12,node13,node14,node15,node16,node17,node18,node19,node20;
Node node28,node30,node40,node80;

void setUp(void){}

void tearDown(void){}

void test_findSmallestNode(void){
  Node *root = &node6;
  int result;
  initNode(&node6,&node3,&node9,1,3,6);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node9,&node8,&node10,0,1,3);
  initNode(&node8,NULL,NULL,0,2,2);
  initNode(&node10,NULL,NULL,0,1,1);

  result = findSmallestNode(&root);
  TEST_ASSERT_EQUAL_PTR(3,result);
}
