#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"
#include "avlRelativeRemove.h"
#include "Rotate.h"
#include "Exception.h"
#include "CException.h"
#include "CExceptionConfig.h"

void setUp(void){
  initPrimitiveNode();
}

void tearDown(void){}

void test_findSmallestRelativeVal_given_Node_6_3_9_8_10_expected_return_3(void){
  Node *root = &node6;
  int result;
  initNode(&node6,&node3,&node9,1,3,6);
  initNode(&node3,NULL,NULL,0,3,3);
  initNode(&node9,&node8,&node10,0,1,3);
  initNode(&node8,NULL,NULL,0,2,2);
  initNode(&node10,NULL,NULL,0,1,1);

  result = findSmallestRelativeVal(&root);
  TEST_ASSERT_EQUAL_PTR(3,result);
}

/*            (6/6)6
 *                 \
 *                (4/4)10
 */
void test_findSmallestRelativeVal_given_Node_6_10_expected_return_6(void){
  Node *root = &node6;
  int result;
  initNode(&node6,NULL,&node10,1,6,6);
  initNode(&node10,NULL,NULL,0,4,4);

  result = findSmallestRelativeVal(&root);
  TEST_ASSERT_EQUAL_PTR(6,result);
}
